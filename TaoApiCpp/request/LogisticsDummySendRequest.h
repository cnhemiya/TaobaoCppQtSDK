#ifndef LOGISTICSDUMMYSENDREQUEST_H
#define LOGISTICSDUMMYSENDREQUEST_H

#include <TaoApiCpp/TaoRequest.h>
#include <TaoApiCpp/TaoParser.h>
#include <TaoApiCpp/response/LogisticsDummySendResponse.h>

/**
 * TOP API: 用户调用该接口可实现无需物流（虚拟）发货,使用该接口发货，交易订单状态会直接变成卖家已发货
 * 
 * @author sd44 <sd44sdd44@yeah.net>
 */
class LogisticsDummySendRequest : public TaoRequest
{
 public:
  virtual QString getApiMethodName() const;

 QString getFeature() const
;  void setFeature (QString feature);

 QString getSellerIp() const
;  void setSellerIp (QString sellerIp);

 qlonglong getTid() const
;  void setTid (qlonglong tid);


  virtual LogisticsDummySendResponse *getResponseClass(const QString &session = "",
                               const QString &accessToken = ""); 

 private:
/**
 * @brief feature参数格式<br> 
范例: identCode=tid1:识别码1,识别码2|tid2:识别码3;machineCode=tid3:3C机器号A,3C机器号B<br> 
identCode为识别码的KEY,machineCode为3C的KEY,多个key之间用”;”分隔<br> 
“tid1:识别码1,识别码2|tid2:识别码3”为identCode对应的value。 
"|"不同商品间的分隔符。<br> 
例1商品和2商品，之间就用"|"分开。<br> 
TID就是商品代表的子订单号，对应taobao.trade.fullinfo.get 接口获得的oid字段。(通过OID可以唯一定位到当前商品上)<br> 
":"TID和具体传入参数间的分隔符。冒号前表示TID,之后代表该商品的参数属性。<br> 
"," 属性间分隔符。（对应商品数量，当存在一个商品的数量超过1个时，用逗号分开）。<br> 
具体:当订单中A商品的数量为2个，其中手机串号分别为"12345","67890"。<br> 
参数格式：identCode=TIDA:12345,67890。 
TIDA对应了A宝贝，冒号后用逗号分隔的"12345","67890".说明本订单A宝贝的数量为2，值分别为"12345","67890"。<br> 
当存在"|"时，就说明订单中存在多个商品，商品间用"|"分隔了开来。|"之后的内容含义同上。
 **/
  QString feature;

/**
 * @brief 商家的IP地址
 **/
  QString sellerIp;

/**
 * @brief 淘宝交易ID
 **/
  qlonglong tid;

};

#endif  /* LOGISTICSDUMMYSENDREQUEST_H */
