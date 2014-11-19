//
//  RTChatSdk.h
//  RTChat
//
//  Created by wang3140@hotmail.com on 14-7-29.
//  Copyright (c) 2014年 RTChatTeam. All rights reserved.
//

#ifndef RTChat_RTChatSdk_h
#define RTChat_RTChatSdk_h

#include "RTChatCommonTypes.h"
#include <functional>

namespace rtchatsdk {

typedef std::function<void (SdkResponseCmd cmdType, SdkErrorCode error, const std::string& msgStr)> pMsgCallFunc;

class RTChatSDKMain {
public:
    static RTChatSDKMain& sharedInstance();
    
    //sdk初始化，只能调用一次(主线程)
    SdkErrorCode initSDK(const std::string& appid, const std::string& key, const char* uniqueid = NULL);
    
    //注册消息回调(主线程)
    void registerMsgCallback(const pMsgCallFunc& func);
    
    //获取SDK当前操作状态，用户发起操作前可以检测一下状态判断可否继续
    SdkOpState getSdkState();
    
    /// 开始录制麦克风数据(主线程)
    bool startRecordVoice(unsigned int labelid);
    
    /// 停止录制麦克风数据(主线程)
    bool stopRecordVoice();
    
    /// 开始播放录制数据(主线程)
    bool startPlayLocalVoice(unsigned int labelid, const char* voiceUrl);
    
    /// 停止当前播放录制数据()
    bool stopPlayLocalVoice();
    
    /// 取消当前录音
    bool cancelRecordedVoice();
};
    
}

#endif