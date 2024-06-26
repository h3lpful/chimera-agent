// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CHIMERA_CHIMERA_H_
#define FLATBUFFERS_GENERATED_CHIMERA_CHIMERA_H_
#include "flatbuffers/flatbuffers.h"
// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace Chimera {

struct Message;
struct MessageBuilder;

struct Message FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MessageBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4
  };
  uint32_t id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ID, 4) &&
           verifier.EndTable();
  }
};

struct MessageBuilder {
  typedef Message Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_id(uint32_t id) {
    fbb_.AddElement<uint32_t>(Message::VT_ID, id, 0);
  }
  explicit MessageBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Message>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Message> CreateMessage(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t id = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_id(id);
  return builder_.Finish();
}

inline const Chimera::Message *GetMessage(const void *buf) {
  return ::flatbuffers::GetRoot<Chimera::Message>(buf);
}

inline const Chimera::Message *GetSizePrefixedMessage(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<Chimera::Message>(buf);
}

inline bool VerifyMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Chimera::Message>(nullptr);
}

inline bool VerifySizePrefixedMessageBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Chimera::Message>(nullptr);
}

inline void FinishMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Chimera::Message> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedMessageBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Chimera::Message> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Chimera

#endif  // FLATBUFFERS_GENERATED_CHIMERA_CHIMERA_H_
