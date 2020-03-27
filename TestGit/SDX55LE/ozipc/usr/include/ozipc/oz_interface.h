
#pragma once

#define CLIENT_OBJ void*
#define REQ_OBJ void*  //CIpcEncordData
#define RES_OBJ void*  //CIpcDecordData

#ifndef __cplusplus
#define bool   _Bool
#define false  0
#define true   1
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  OZ_SYNC_REQ,
  OZ_ASYNC_REQ,
  OZ_UNSOL
} RequestType;

typedef void (*serverMsgHandle)(const void* aChHandle, int aReq,
                            RES_OBJ aIn, REQ_OBJ aOut);

typedef void (*clientMsgHandle)(int aReq, RES_OBJ aIn);

//ipc server
void oz_createServer(const char* aSocketName, serverMsgHandle aMsgHandler);

//ipc client
CLIENT_OBJ oz_connectServer(const char* aSocketName, clientMsgHandle aMsgHandler);

RES_OBJ oz_sendSyncCmd(REQ_OBJ aReqData);

int oz_sendAsyncCmd(REQ_OBJ aReqData);

int oz_registerEvent(CLIENT_OBJ aChObj, int aEventId);

int oz_unRregisterEvent(CLIENT_OBJ aChObj, int aEventId);

REQ_OBJ oz_newOutObject(CLIENT_OBJ aChObj, int aReqId, RequestType aReqType, int aSerial);

REQ_OBJ oz_newOutUnsolObject(int aEventId);

void oz_delReqObj(REQ_OBJ aReqObj);

void oz_delResObj(RES_OBJ aResObj);

//serialize and de-serialize
int oz_readInt32(RES_OBJ aIn);

char* oz_strdup_readString(RES_OBJ aIn);

double oz_readDouble(RES_OBJ aIn);

unsigned int oz_readUInt32(RES_OBJ aIn);

void oz_writeInt32(REQ_OBJ aOut, int aValue);

void oz_writeStr(REQ_OBJ aOut, char* aStr);

void oz_writeDouble(REQ_OBJ aOut, double aValue);

void oz_writeUInt32(REQ_OBJ aOut, unsigned int aValue);

//send api
bool oz_sendResponse(const void* aChHandle, RES_OBJ aInData, REQ_OBJ aOutData);

//api only for server
void oz_sendUnsolNotification(REQ_OBJ aOutData);

#ifdef __cplusplus
}
#endif
