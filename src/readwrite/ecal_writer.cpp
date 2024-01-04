//
// Created by uig61636 on 28.12.2023.
//

#include "ecal_writer.h"

eCAL::CDataWriter::CDataWriter(bool allow_zero_copy /* = false*/){
    this->allow_zero_copy = allow_zero_copy;
}
/*
size_t eCAL::CDataWriter::Write(CPayloadWriter& payload_, long long time_, long long id_) {
    if (allow_zero_copy)
    {
        // write to shm layer (write content into the opened memory file without additional copy)
        shm_sent = m_writer.shm.Write(payload_, wattr);
    }
        // multiple layer are active -> we make a copy and use that one
    else
    {
        // wrap the buffer into a payload object
        CBufferPayloadWriter payload_buf(m_payload_buffer.data(), m_payload_buffer.size());
        // write to shm layer (write content into the opened memory file without additional copy)
        shm_sent = m_writer.shm.Write(payload_buf, wattr);
    }
}
*/