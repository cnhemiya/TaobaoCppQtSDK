#ifndef WANGWANGESERVICECHATPEERSGETRESPONSE_H
#define WANGWANGESERVICECHATPEERSGETRESPONSE_H

#include <TaoApiCpp/TaoResponse.h>
#include <QList>
#include <TaoApiCpp/domain/Chatpeer.h>


/**
 * @brief TOP RESPONSE API: 获取聊天对象列表，只能获取最近1个月内的数据且查询时间段<=7天,只支持xml返回 。
 * 
 * @author sd44 <sd44sdd44@yeah.net>
 */
class WangwangEserviceChatpeersGetResponse : public TaoResponse
{
public:
 virtual ~WangwangEserviceChatpeersGetResponse() { }

  QList<Chatpeer> getChatpeers() const;
  void setChatpeers (QList<Chatpeer> chatpeers);  qlonglong getCount() const;
  void setCount (qlonglong count);  qlonglong getRet() const;
  void setRet (qlonglong ret);
  virtual void parseNormalResponse();

 private:
/**
 * @brief 聊天对象ID列表
 **/
  QList<Chatpeer> chatpeers;

/**
 * @brief 成员数目。
 **/
  qlonglong count;

/**
 * @brief 返回码： 
10000:成功； 

60000：时间非法，包括1)时间段超过7天,或2)起始时间距今超过30天，或3)时间格式不对； 

50000：聊天用户ID不是该店铺的帐号； 

40000：系统错误，包括必填参数为空。
 **/
  qlonglong ret;

};

#endif
