// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto
// Protobuf C++ Version: 5.26.1

#include "test.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace Test {

inline constexpr Person::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : list_of_jobs_{},
        name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        address_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        cur_job_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        cur_salary_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Person::Person(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace Test
static ::_pb::Metadata file_level_metadata_test_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_test_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_test_2eproto = nullptr;
const ::uint32_t
    TableStruct_test_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Test::Person, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Test::Person, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::Test::Person, _impl_.address_),
        PROTOBUF_FIELD_OFFSET(::Test::Person, _impl_.list_of_jobs_),
        PROTOBUF_FIELD_OFFSET(::Test::Person, _impl_.cur_job_),
        PROTOBUF_FIELD_OFFSET(::Test::Person, _impl_.cur_salary_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Test::Person)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::Test::_Person_default_instance_._instance,
};
const char descriptor_table_protodef_test_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\ntest.proto\022\004Test\"b\n\006Person\022\014\n\004name\030\001 \001"
    "(\t\022\017\n\007address\030\002 \001(\t\022\024\n\014list_of_jobs\030\003 \003("
    "\t\022\017\n\007cur_job\030\004 \001(\t\022\022\n\ncur_salary\030\005 \001(\001b\006"
    "proto3"
};
static ::absl::once_flag descriptor_table_test_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_test_2eproto = {
    false,
    false,
    126,
    descriptor_table_protodef_test_2eproto,
    "test.proto",
    &descriptor_table_test_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_test_2eproto::offsets,
    file_level_metadata_test_2eproto,
    file_level_enum_descriptors_test_2eproto,
    file_level_service_descriptors_test_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_test_2eproto_getter() {
  return &descriptor_table_test_2eproto;
}
namespace Test {
// ===================================================================

class Person::_Internal {
 public:
};

Person::Person(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Test.Person)
}
inline PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : list_of_jobs_{visibility, arena, from.list_of_jobs_},
        name_(arena, from.name_),
        address_(arena, from.address_),
        cur_job_(arena, from.cur_job_),
        _cached_size_{0} {}

Person::Person(
    ::google::protobuf::Arena* arena,
    const Person& from)
    : ::google::protobuf::Message(arena) {
  Person* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.cur_salary_ = from._impl_.cur_salary_;

  // @@protoc_insertion_point(copy_constructor:Test.Person)
}
inline PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : list_of_jobs_{visibility, arena},
        name_(arena),
        address_(arena),
        cur_job_(arena),
        _cached_size_{0} {}

inline void Person::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.cur_salary_ = {};
}
Person::~Person() {
  // @@protoc_insertion_point(destructor:Test.Person)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Person::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.name_.Destroy();
  _impl_.address_.Destroy();
  _impl_.cur_job_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Person::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Person, _impl_._cached_size_),
              false,
          },
          &Person::MergeImpl,
          &Person::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:Test.Person)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.list_of_jobs_.Clear();
  _impl_.name_.ClearToEmpty();
  _impl_.address_.ClearToEmpty();
  _impl_.cur_job_.ClearToEmpty();
  _impl_.cur_salary_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Person::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 0, 50, 2> Person::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Person_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Test::Person>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string name = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.name_)}},
    // string address = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.address_)}},
    // repeated string list_of_jobs = 3;
    {::_pbi::TcParser::FastUR1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.list_of_jobs_)}},
    // string cur_job = 4;
    {::_pbi::TcParser::FastUS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.cur_job_)}},
    // double cur_salary = 5;
    {::_pbi::TcParser::FastF64S1,
     {41, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.cur_salary_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // string name = 1;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.name_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string address = 2;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.address_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // repeated string list_of_jobs = 3;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.list_of_jobs_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kUtf8String | ::_fl::kRepSString)},
    // string cur_job = 4;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.cur_job_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // double cur_salary = 5;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.cur_salary_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
  }},
  // no aux_entries
  {{
    "\13\4\7\14\7\0\0\0"
    "Test.Person"
    "name"
    "address"
    "list_of_jobs"
    "cur_job"
  }},
};

::uint8_t* Person::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Test.Person)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    const std::string& _s = this->_internal_name();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Test.Person.name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // string address = 2;
  if (!this->_internal_address().empty()) {
    const std::string& _s = this->_internal_address();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Test.Person.address");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // repeated string list_of_jobs = 3;
  for (int i = 0, n = this->_internal_list_of_jobs_size(); i < n; ++i) {
    const auto& s = this->_internal_list_of_jobs().Get(i);
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        s.data(), static_cast<int>(s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Test.Person.list_of_jobs");
    target = stream->WriteString(3, s, target);
  }

  // string cur_job = 4;
  if (!this->_internal_cur_job().empty()) {
    const std::string& _s = this->_internal_cur_job();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Test.Person.cur_job");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // double cur_salary = 5;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_cur_salary = this->_internal_cur_salary();
  ::uint64_t raw_cur_salary;
  memcpy(&raw_cur_salary, &tmp_cur_salary, sizeof(tmp_cur_salary));
  if (raw_cur_salary != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        5, this->_internal_cur_salary(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Test.Person)
  return target;
}

::size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Test.Person)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string list_of_jobs = 3;
  total_size += 1 * ::google::protobuf::internal::FromIntSize(_internal_list_of_jobs().size());
  for (int i = 0, n = _internal_list_of_jobs().size(); i < n; ++i) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
        _internal_list_of_jobs().Get(i));
  }
  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_name());
  }

  // string address = 2;
  if (!this->_internal_address().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_address());
  }

  // string cur_job = 4;
  if (!this->_internal_cur_job().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_cur_job());
  }

  // double cur_salary = 5;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_cur_salary = this->_internal_cur_salary();
  ::uint64_t raw_cur_salary;
  memcpy(&raw_cur_salary, &tmp_cur_salary, sizeof(tmp_cur_salary));
  if (raw_cur_salary != 0) {
    total_size += 9;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Person::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Test.Person)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_list_of_jobs()->MergeFrom(from._internal_list_of_jobs());
  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_address().empty()) {
    _this->_internal_set_address(from._internal_address());
  }
  if (!from._internal_cur_job().empty()) {
    _this->_internal_set_cur_job(from._internal_cur_job());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_cur_salary = from._internal_cur_salary();
  ::uint64_t raw_cur_salary;
  memcpy(&raw_cur_salary, &tmp_cur_salary, sizeof(tmp_cur_salary));
  if (raw_cur_salary != 0) {
    _this->_impl_.cur_salary_ = from._impl_.cur_salary_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Test.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.list_of_jobs_.InternalSwap(&other->_impl_.list_of_jobs_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.address_, &other->_impl_.address_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.cur_job_, &other->_impl_.cur_job_, arena);
        swap(_impl_.cur_salary_, other->_impl_.cur_salary_);
}

::google::protobuf::Metadata Person::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_test_2eproto_getter,
                                   &descriptor_table_test_2eproto_once,
                                   file_level_metadata_test_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace Test
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_test_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
