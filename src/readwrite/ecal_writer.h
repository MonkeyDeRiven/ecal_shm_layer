//
// Created by uig61636 on 28.12.2023.
//
#ifndef ECAL_SHM_LAYER_ECAL_WRITER_H
#define ECAL_SHM_LAYER_ECAL_WRITER_H

#include <corecrt.h>
#include <readwrite/ecal_writer.h>
#include "ecal/ecal_payload_writer.h"


namespace eCAL {
    class CDataWriter {

    public:
        CDataWriter(bool allow_zero_copy = false);

        size_t Write(CPayloadWriter &payload_, long long time_, long long id_);

    protected:
        bool allow_zero_copy;

    };
}

#endif //ECAL_SHM_LAYER_ECAL_WRITER_H
