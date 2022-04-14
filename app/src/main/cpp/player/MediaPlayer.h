/**
 *
 * Created by 公众号：字节流动 on 2021/12/16.
 * https://github.com/githubhaohao/LearnFFmpeg
 * 最新文章首发于公众号：字节流动，有疑问或者技术交流可以添加微信 Byte-Flow ,领取视频教程, 拉你进技术交流群
 *
 * */

#ifndef LEARNFFMPEG_MEDIAPLAYER_H
#define LEARNFFMPEG_MEDIAPLAYER_H

#include <jni.h>
#include <decoder/VideoDecoder.h>
#include <decoder/AudioDecoder.h>
#include <render/audio/AudioRender.h>

#define JAVA_PLAYER_EVENT_CALLBACK_API_NAME "playerEventCallback"

#define MEDIA_PARAM_VIDEO_WIDTH         0x0001
#define MEDIA_PARAM_VIDEO_HEIGHT        0x0002
#define MEDIA_PARAM_VIDEO_DURATION      0x0003

#define MEDIA_PARAM_ASSET_MANAGER       0x0020


class MediaPlayer {
public:
    MediaPlayer(){};
    virtual ~MediaPlayer(){};
    /*初始化数据*/
    virtual void Init(JNIEnv *jniEnv, jobject obj, char *url, int renderType, jobject surface) = 0;
    /*释放数据*/
    virtual void UnInit() = 0;
    /*播放*/
    virtual void Play() = 0;
    /*暂停*/
    virtual void Pause() = 0;
    /*停止*/
    virtual void Stop() = 0;
    /*跳转*/
    virtual void SeekToPosition(float position) = 0;
    /*获取媒体参数*/
    virtual long GetMediaParams(int paramType) = 0;
    /*设置媒体参数*/
    virtual void SetMediaParams(int paramType, jobject obj){}
    /*获取当前线程env*/
    virtual JNIEnv *GetJNIEnv(bool *isAttach) = 0;
    virtual jobject GetJavaObj() = 0;
    virtual JavaVM *GetJavaVM() = 0;
    /*用于线程切换 创建env*/
    JavaVM *m_JavaVM = nullptr;
    /*java 调用层对象 用户反射调用*/
    jobject m_JavaObj = nullptr;
};

#endif //LEARNFFMPEG_MEDIAPLAYER_H
