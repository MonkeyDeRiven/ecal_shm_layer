#include <iostream>
#include "include/ecal/ecal_payload_writer.h"
#include "src/io/shm/ecal_memfile_sync.h"
#include "src/readwrite/ecal_writer_data.h"
#include "src/readwrite/ecal_buffer_payload_writer.h"
#include "src/readwrite/ecal_writer.h"
#include "src/io/shm/ecal_memfile_sync.h"


eCAL::SWriterAttr getDefaultSWriterAttr(bool allow_zero_copy){
    eCAL::SWriterAttr attr_ = eCAL::SWriterAttr();
    attr_.zero_copy = allow_zero_copy;
    attr_.bandwidth = 100;
    attr_.acknowledge_timeout_ms = 1000;

    return attr_;
}

eCAL::SSyncMemoryFileAttr getDefaultSSyncAttr(){
    auto attributes = eCAL::SSyncMemoryFileAttr();

    attributes.min_size = 100;
    attributes.reserve = 1000;
    attributes.timeout_ack_ms = 2000;
    attributes.timeout_open_ms = 4000;

    return attributes;
}

int main() {
    bool zeroCopy = false;
    auto attr = getDefaultSSyncAttr();
    char* buf_ = "this is my first message";
    size_t test = 1000;
    eCAL::CSyncMemoryFile m_sync = eCAL::CSyncMemoryFile("base", test, attr);
    eCAL::CBufferPayloadWriter payload_( buf_, 25 );
    m_sync.Write(payload_, getDefaultSWriterAttr(false));

    return 0;
}

void createPayload(){
    //auto* _payload = new eCAL::CPayloadWriter();
}
