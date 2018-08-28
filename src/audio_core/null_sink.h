// Copyright 2018 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "audio_core/sink.h"

namespace AudioCore {

class NullSink final : public Sink {
public:
    explicit NullSink(std::string){};
    ~NullSink() override = default;

    SinkStream& AcquireSinkStream(u32 /*sample_rate*/, u32 /*num_channels*/,
                                  const std::string& /*name*/) override {
        return null_sink_stream;
    }

private:
    struct NullSinkStreamImpl final : SinkStream {
        void EnqueueSamples(u32 /*num_channels*/, const std::vector<s16>& /*samples*/) override {}

        size_t SamplesInQueue() const override {
            return 0;
        }
    } null_sink_stream;
};

} // namespace AudioCore
