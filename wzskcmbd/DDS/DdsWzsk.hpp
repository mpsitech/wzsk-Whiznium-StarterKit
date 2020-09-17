

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsWzsk.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DdsWzsk_509372353_hpp
#define DdsWzsk_509372353_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

typedef char tinyint;
struct tinyint_AliasTag_t {};

typedef uint8_t utinyint;
struct utinyint_AliasTag_t {};

typedef int16_t smallint;
struct smallint_AliasTag_t {};

typedef uint16_t usmallint;
struct usmallint_AliasTag_t {};

typedef int32_t _cxx_int;
struct _cxx_int_AliasTag_t {};

typedef uint32_t uint;
struct uint_AliasTag_t {};

typedef ::rti::core::int64 bigint;
struct bigint_AliasTag_t {};

typedef ::rti::core::uint64 ubigint;
struct ubigint_AliasTag_t {};

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< float >;
template class NDDSUSERDllExport std::vector< float >;
#endif
class NDDSUSERDllExport DdsFloatmat {
  public:
    DdsFloatmat();

    DdsFloatmat(
        const ::rti::core::bounded_sequence< float, 100 >& vec,
        uint32_t M,
        uint32_t N);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DdsFloatmat (DdsFloatmat&&) = default;
    DdsFloatmat& operator=(DdsFloatmat&&) = default;
    DdsFloatmat& operator=(const DdsFloatmat&) = default;
    DdsFloatmat(const DdsFloatmat&) = default;
    #else
    DdsFloatmat(DdsFloatmat&& other_) OMG_NOEXCEPT;  
    DdsFloatmat& operator=(DdsFloatmat&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    ::rti::core::bounded_sequence< float, 100 >& vec() OMG_NOEXCEPT {
        return m_vec_;
    }

    const ::rti::core::bounded_sequence< float, 100 >& vec() const OMG_NOEXCEPT {
        return m_vec_;
    }

    void vec(const ::rti::core::bounded_sequence< float, 100 >& value) {
        m_vec_ = value;
    }

    uint32_t& M() OMG_NOEXCEPT {
        return m_M_;
    }

    const uint32_t& M() const OMG_NOEXCEPT {
        return m_M_;
    }

    void M(uint32_t value) {
        m_M_ = value;
    }

    uint32_t& N() OMG_NOEXCEPT {
        return m_N_;
    }

    const uint32_t& N() const OMG_NOEXCEPT {
        return m_N_;
    }

    void N(uint32_t value) {
        m_N_ = value;
    }

    bool operator == (const DdsFloatmat& other_) const;
    bool operator != (const DdsFloatmat& other_) const;

    void swap(DdsFloatmat& other_) OMG_NOEXCEPT ;

  private:

    ::rti::core::bounded_sequence< float, 100 > m_vec_;
    uint32_t m_M_;
    uint32_t m_N_;

};

inline void swap(DdsFloatmat& a, DdsFloatmat& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DdsFloatmat& sample);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< double >;
template class NDDSUSERDllExport std::vector< double >;
#endif
class NDDSUSERDllExport DdsDoublemat {
  public:
    DdsDoublemat();

    DdsDoublemat(
        const ::rti::core::bounded_sequence< double, 100 >& vec,
        uint32_t M,
        uint32_t N);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DdsDoublemat (DdsDoublemat&&) = default;
    DdsDoublemat& operator=(DdsDoublemat&&) = default;
    DdsDoublemat& operator=(const DdsDoublemat&) = default;
    DdsDoublemat(const DdsDoublemat&) = default;
    #else
    DdsDoublemat(DdsDoublemat&& other_) OMG_NOEXCEPT;  
    DdsDoublemat& operator=(DdsDoublemat&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    ::rti::core::bounded_sequence< double, 100 >& vec() OMG_NOEXCEPT {
        return m_vec_;
    }

    const ::rti::core::bounded_sequence< double, 100 >& vec() const OMG_NOEXCEPT {
        return m_vec_;
    }

    void vec(const ::rti::core::bounded_sequence< double, 100 >& value) {
        m_vec_ = value;
    }

    uint32_t& M() OMG_NOEXCEPT {
        return m_M_;
    }

    const uint32_t& M() const OMG_NOEXCEPT {
        return m_M_;
    }

    void M(uint32_t value) {
        m_M_ = value;
    }

    uint32_t& N() OMG_NOEXCEPT {
        return m_N_;
    }

    const uint32_t& N() const OMG_NOEXCEPT {
        return m_N_;
    }

    void N(uint32_t value) {
        m_N_ = value;
    }

    bool operator == (const DdsDoublemat& other_) const;
    bool operator != (const DdsDoublemat& other_) const;

    void swap(DdsDoublemat& other_) OMG_NOEXCEPT ;

  private:

    ::rti::core::bounded_sequence< double, 100 > m_vec_;
    uint32_t m_M_;
    uint32_t m_N_;

};

inline void swap(DdsDoublemat& a, DdsDoublemat& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DdsDoublemat& sample);

typedef std::string stringvec;
struct stringvec_AliasTag_t {};

typedef std::string vecsref;
struct vecsref_AliasTag_t {};
namespace DdsJobWzskSrcSysinfo {

    class NDDSUSERDllExport loadAllLoadCore0LoadCore1LoadCore2LoadCore3 {
      public:
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3();

        loadAllLoadCore0LoadCore1LoadCore2LoadCore3(
            const ::rti::core::bounded_sequence< float, 60 >& loadAll,
            const ::rti::core::bounded_sequence< float, 60 >& loadCore0,
            const ::rti::core::bounded_sequence< float, 60 >& loadCore1,
            const ::rti::core::bounded_sequence< float, 60 >& loadCore2,
            const ::rti::core::bounded_sequence< float, 60 >& loadCore3);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 (loadAllLoadCore0LoadCore1LoadCore2LoadCore3&&) = default;
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3& operator=(loadAllLoadCore0LoadCore1LoadCore2LoadCore3&&) = default;
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3& operator=(const loadAllLoadCore0LoadCore1LoadCore2LoadCore3&) = default;
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3(const loadAllLoadCore0LoadCore1LoadCore2LoadCore3&) = default;
        #else
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3(loadAllLoadCore0LoadCore1LoadCore2LoadCore3&& other_) OMG_NOEXCEPT;  
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3& operator=(loadAllLoadCore0LoadCore1LoadCore2LoadCore3&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< float, 60 >& loadAll() OMG_NOEXCEPT {
            return m_loadAll_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& loadAll() const OMG_NOEXCEPT {
            return m_loadAll_;
        }

        void loadAll(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m_loadAll_ = value;
        }

        ::rti::core::bounded_sequence< float, 60 >& loadCore0() OMG_NOEXCEPT {
            return m_loadCore0_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& loadCore0() const OMG_NOEXCEPT {
            return m_loadCore0_;
        }

        void loadCore0(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m_loadCore0_ = value;
        }

        ::rti::core::bounded_sequence< float, 60 >& loadCore1() OMG_NOEXCEPT {
            return m_loadCore1_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& loadCore1() const OMG_NOEXCEPT {
            return m_loadCore1_;
        }

        void loadCore1(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m_loadCore1_ = value;
        }

        ::rti::core::bounded_sequence< float, 60 >& loadCore2() OMG_NOEXCEPT {
            return m_loadCore2_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& loadCore2() const OMG_NOEXCEPT {
            return m_loadCore2_;
        }

        void loadCore2(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m_loadCore2_ = value;
        }

        ::rti::core::bounded_sequence< float, 60 >& loadCore3() OMG_NOEXCEPT {
            return m_loadCore3_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& loadCore3() const OMG_NOEXCEPT {
            return m_loadCore3_;
        }

        void loadCore3(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m_loadCore3_ = value;
        }

        bool operator == (const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_) const;
        bool operator != (const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_) const;

        void swap(loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< float, 60 > m_loadAll_;
        ::rti::core::bounded_sequence< float, 60 > m_loadCore0_;
        ::rti::core::bounded_sequence< float, 60 > m_loadCore1_;
        ::rti::core::bounded_sequence< float, 60 > m_loadCore2_;
        ::rti::core::bounded_sequence< float, 60 > m_loadCore3_;

    };

    inline void swap(loadAllLoadCore0LoadCore1LoadCore2LoadCore3& a, loadAllLoadCore0LoadCore1LoadCore2LoadCore3& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample);

    class NDDSUSERDllExport temp {
      public:
        temp();

        explicit temp(
            const ::rti::core::bounded_sequence< float, 60 >& _temp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        temp (temp&&) = default;
        temp& operator=(temp&&) = default;
        temp& operator=(const temp&) = default;
        temp(const temp&) = default;
        #else
        temp(temp&& other_) OMG_NOEXCEPT;  
        temp& operator=(temp&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< float, 60 >& _temp() OMG_NOEXCEPT {
            return m__temp_;
        }

        const ::rti::core::bounded_sequence< float, 60 >& _temp() const OMG_NOEXCEPT {
            return m__temp_;
        }

        void _temp(const ::rti::core::bounded_sequence< float, 60 >& value) {
            m__temp_ = value;
        }

        bool operator == (const temp& other_) const;
        bool operator != (const temp& other_) const;

        void swap(temp& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< float, 60 > m__temp_;

    };

    inline void swap(temp& a, temp& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const temp& sample);

} // namespace DdsJobWzskSrcSysinfo  
namespace DdsJobWzskIprTrace {

    class NDDSUSERDllExport setLevel_req {
      public:
        setLevel_req();

        setLevel_req(
            uint8_t levelOn,
            uint8_t levelOff);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setLevel_req (setLevel_req&&) = default;
        setLevel_req& operator=(setLevel_req&&) = default;
        setLevel_req& operator=(const setLevel_req&) = default;
        setLevel_req(const setLevel_req&) = default;
        #else
        setLevel_req(setLevel_req&& other_) OMG_NOEXCEPT;  
        setLevel_req& operator=(setLevel_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& levelOn() OMG_NOEXCEPT {
            return m_levelOn_;
        }

        const uint8_t& levelOn() const OMG_NOEXCEPT {
            return m_levelOn_;
        }

        void levelOn(uint8_t value) {
            m_levelOn_ = value;
        }

        uint8_t& levelOff() OMG_NOEXCEPT {
            return m_levelOff_;
        }

        const uint8_t& levelOff() const OMG_NOEXCEPT {
            return m_levelOff_;
        }

        void levelOff(uint8_t value) {
            m_levelOff_ = value;
        }

        bool operator == (const setLevel_req& other_) const;
        bool operator != (const setLevel_req& other_) const;

        void swap(setLevel_req& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_levelOn_;
        uint8_t m_levelOff_;

    };

    inline void swap(setLevel_req& a, setLevel_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setLevel_req& sample);

    class NDDSUSERDllExport setLevel_reply {
      public:
        setLevel_reply();

        explicit setLevel_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setLevel_reply (setLevel_reply&&) = default;
        setLevel_reply& operator=(setLevel_reply&&) = default;
        setLevel_reply& operator=(const setLevel_reply&) = default;
        setLevel_reply(const setLevel_reply&) = default;
        #else
        setLevel_reply(setLevel_reply&& other_) OMG_NOEXCEPT;  
        setLevel_reply& operator=(setLevel_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setLevel_reply& other_) const;
        bool operator != (const setLevel_reply& other_) const;

        void swap(setLevel_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setLevel_reply& a, setLevel_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setLevel_reply& sample);

    class NDDSUSERDllExport setRoi_req {
      public:
        setRoi_req();

        setRoi_req(
            int32_t roiAx,
            int32_t roiAy,
            int32_t roiBx,
            int32_t roiBy,
            int32_t roiCx,
            int32_t roiCy,
            int32_t roiDx,
            int32_t roiDy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoi_req (setRoi_req&&) = default;
        setRoi_req& operator=(setRoi_req&&) = default;
        setRoi_req& operator=(const setRoi_req&) = default;
        setRoi_req(const setRoi_req&) = default;
        #else
        setRoi_req(setRoi_req&& other_) OMG_NOEXCEPT;  
        setRoi_req& operator=(setRoi_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t& roiAx() OMG_NOEXCEPT {
            return m_roiAx_;
        }

        const int32_t& roiAx() const OMG_NOEXCEPT {
            return m_roiAx_;
        }

        void roiAx(int32_t value) {
            m_roiAx_ = value;
        }

        int32_t& roiAy() OMG_NOEXCEPT {
            return m_roiAy_;
        }

        const int32_t& roiAy() const OMG_NOEXCEPT {
            return m_roiAy_;
        }

        void roiAy(int32_t value) {
            m_roiAy_ = value;
        }

        int32_t& roiBx() OMG_NOEXCEPT {
            return m_roiBx_;
        }

        const int32_t& roiBx() const OMG_NOEXCEPT {
            return m_roiBx_;
        }

        void roiBx(int32_t value) {
            m_roiBx_ = value;
        }

        int32_t& roiBy() OMG_NOEXCEPT {
            return m_roiBy_;
        }

        const int32_t& roiBy() const OMG_NOEXCEPT {
            return m_roiBy_;
        }

        void roiBy(int32_t value) {
            m_roiBy_ = value;
        }

        int32_t& roiCx() OMG_NOEXCEPT {
            return m_roiCx_;
        }

        const int32_t& roiCx() const OMG_NOEXCEPT {
            return m_roiCx_;
        }

        void roiCx(int32_t value) {
            m_roiCx_ = value;
        }

        int32_t& roiCy() OMG_NOEXCEPT {
            return m_roiCy_;
        }

        const int32_t& roiCy() const OMG_NOEXCEPT {
            return m_roiCy_;
        }

        void roiCy(int32_t value) {
            m_roiCy_ = value;
        }

        int32_t& roiDx() OMG_NOEXCEPT {
            return m_roiDx_;
        }

        const int32_t& roiDx() const OMG_NOEXCEPT {
            return m_roiDx_;
        }

        void roiDx(int32_t value) {
            m_roiDx_ = value;
        }

        int32_t& roiDy() OMG_NOEXCEPT {
            return m_roiDy_;
        }

        const int32_t& roiDy() const OMG_NOEXCEPT {
            return m_roiDy_;
        }

        void roiDy(int32_t value) {
            m_roiDy_ = value;
        }

        bool operator == (const setRoi_req& other_) const;
        bool operator != (const setRoi_req& other_) const;

        void swap(setRoi_req& other_) OMG_NOEXCEPT ;

      private:

        int32_t m_roiAx_;
        int32_t m_roiAy_;
        int32_t m_roiBx_;
        int32_t m_roiBy_;
        int32_t m_roiCx_;
        int32_t m_roiCy_;
        int32_t m_roiDx_;
        int32_t m_roiDy_;

    };

    inline void swap(setRoi_req& a, setRoi_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoi_req& sample);

    class NDDSUSERDllExport setRoi_reply {
      public:
        setRoi_reply();

        explicit setRoi_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoi_reply (setRoi_reply&&) = default;
        setRoi_reply& operator=(setRoi_reply&&) = default;
        setRoi_reply& operator=(const setRoi_reply&) = default;
        setRoi_reply(const setRoi_reply&) = default;
        #else
        setRoi_reply(setRoi_reply&& other_) OMG_NOEXCEPT;  
        setRoi_reply& operator=(setRoi_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setRoi_reply& other_) const;
        bool operator != (const setRoi_reply& other_) const;

        void swap(setRoi_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setRoi_reply& a, setRoi_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoi_reply& sample);

    class NDDSUSERDllExport setRoiNotFull_req {
      public:
        setRoiNotFull_req();

        explicit setRoiNotFull_req(
            bool roiNotFull);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoiNotFull_req (setRoiNotFull_req&&) = default;
        setRoiNotFull_req& operator=(setRoiNotFull_req&&) = default;
        setRoiNotFull_req& operator=(const setRoiNotFull_req&) = default;
        setRoiNotFull_req(const setRoiNotFull_req&) = default;
        #else
        setRoiNotFull_req(setRoiNotFull_req&& other_) OMG_NOEXCEPT;  
        setRoiNotFull_req& operator=(setRoiNotFull_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& roiNotFull() OMG_NOEXCEPT {
            return m_roiNotFull_;
        }

        const bool& roiNotFull() const OMG_NOEXCEPT {
            return m_roiNotFull_;
        }

        void roiNotFull(bool value) {
            m_roiNotFull_ = value;
        }

        bool operator == (const setRoiNotFull_req& other_) const;
        bool operator != (const setRoiNotFull_req& other_) const;

        void swap(setRoiNotFull_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_roiNotFull_;

    };

    inline void swap(setRoiNotFull_req& a, setRoiNotFull_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoiNotFull_req& sample);

    class NDDSUSERDllExport setRoiNotFull_reply {
      public:
        setRoiNotFull_reply();

        explicit setRoiNotFull_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoiNotFull_reply (setRoiNotFull_reply&&) = default;
        setRoiNotFull_reply& operator=(setRoiNotFull_reply&&) = default;
        setRoiNotFull_reply& operator=(const setRoiNotFull_reply&) = default;
        setRoiNotFull_reply(const setRoiNotFull_reply&) = default;
        #else
        setRoiNotFull_reply(setRoiNotFull_reply&& other_) OMG_NOEXCEPT;  
        setRoiNotFull_reply& operator=(setRoiNotFull_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setRoiNotFull_reply& other_) const;
        bool operator != (const setRoiNotFull_reply& other_) const;

        void swap(setRoiNotFull_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setRoiNotFull_reply& a, setRoiNotFull_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoiNotFull_reply& sample);

    class NDDSUSERDllExport pOnLeftPOnRight {
      public:
        pOnLeftPOnRight();

        pOnLeftPOnRight(
            float pOnLeft,
            float pOnRight);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        pOnLeftPOnRight (pOnLeftPOnRight&&) = default;
        pOnLeftPOnRight& operator=(pOnLeftPOnRight&&) = default;
        pOnLeftPOnRight& operator=(const pOnLeftPOnRight&) = default;
        pOnLeftPOnRight(const pOnLeftPOnRight&) = default;
        #else
        pOnLeftPOnRight(pOnLeftPOnRight&& other_) OMG_NOEXCEPT;  
        pOnLeftPOnRight& operator=(pOnLeftPOnRight&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& pOnLeft() OMG_NOEXCEPT {
            return m_pOnLeft_;
        }

        const float& pOnLeft() const OMG_NOEXCEPT {
            return m_pOnLeft_;
        }

        void pOnLeft(float value) {
            m_pOnLeft_ = value;
        }

        float& pOnRight() OMG_NOEXCEPT {
            return m_pOnRight_;
        }

        const float& pOnRight() const OMG_NOEXCEPT {
            return m_pOnRight_;
        }

        void pOnRight(float value) {
            m_pOnRight_ = value;
        }

        bool operator == (const pOnLeftPOnRight& other_) const;
        bool operator != (const pOnLeftPOnRight& other_) const;

        void swap(pOnLeftPOnRight& other_) OMG_NOEXCEPT ;

      private:

        float m_pOnLeft_;
        float m_pOnRight_;

    };

    inline void swap(pOnLeftPOnRight& a, pOnLeftPOnRight& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const pOnLeftPOnRight& sample);

    class NDDSUSERDllExport levelOnLevelOff {
      public:
        levelOnLevelOff();

        levelOnLevelOff(
            uint8_t levelOn,
            uint8_t levelOff);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        levelOnLevelOff (levelOnLevelOff&&) = default;
        levelOnLevelOff& operator=(levelOnLevelOff&&) = default;
        levelOnLevelOff& operator=(const levelOnLevelOff&) = default;
        levelOnLevelOff(const levelOnLevelOff&) = default;
        #else
        levelOnLevelOff(levelOnLevelOff&& other_) OMG_NOEXCEPT;  
        levelOnLevelOff& operator=(levelOnLevelOff&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& levelOn() OMG_NOEXCEPT {
            return m_levelOn_;
        }

        const uint8_t& levelOn() const OMG_NOEXCEPT {
            return m_levelOn_;
        }

        void levelOn(uint8_t value) {
            m_levelOn_ = value;
        }

        uint8_t& levelOff() OMG_NOEXCEPT {
            return m_levelOff_;
        }

        const uint8_t& levelOff() const OMG_NOEXCEPT {
            return m_levelOff_;
        }

        void levelOff(uint8_t value) {
            m_levelOff_ = value;
        }

        bool operator == (const levelOnLevelOff& other_) const;
        bool operator != (const levelOnLevelOff& other_) const;

        void swap(levelOnLevelOff& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_levelOn_;
        uint8_t m_levelOff_;

    };

    inline void swap(levelOnLevelOff& a, levelOnLevelOff& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const levelOnLevelOff& sample);

    class NDDSUSERDllExport roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy {
      public:
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy();

        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(
            int32_t roiAx,
            int32_t roiAy,
            int32_t roiBx,
            int32_t roiBy,
            int32_t roiCx,
            int32_t roiCy,
            int32_t roiDx,
            int32_t roiDy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy (roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&) = default;
        #else
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&& other_) OMG_NOEXCEPT;  
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t& roiAx() OMG_NOEXCEPT {
            return m_roiAx_;
        }

        const int32_t& roiAx() const OMG_NOEXCEPT {
            return m_roiAx_;
        }

        void roiAx(int32_t value) {
            m_roiAx_ = value;
        }

        int32_t& roiAy() OMG_NOEXCEPT {
            return m_roiAy_;
        }

        const int32_t& roiAy() const OMG_NOEXCEPT {
            return m_roiAy_;
        }

        void roiAy(int32_t value) {
            m_roiAy_ = value;
        }

        int32_t& roiBx() OMG_NOEXCEPT {
            return m_roiBx_;
        }

        const int32_t& roiBx() const OMG_NOEXCEPT {
            return m_roiBx_;
        }

        void roiBx(int32_t value) {
            m_roiBx_ = value;
        }

        int32_t& roiBy() OMG_NOEXCEPT {
            return m_roiBy_;
        }

        const int32_t& roiBy() const OMG_NOEXCEPT {
            return m_roiBy_;
        }

        void roiBy(int32_t value) {
            m_roiBy_ = value;
        }

        int32_t& roiCx() OMG_NOEXCEPT {
            return m_roiCx_;
        }

        const int32_t& roiCx() const OMG_NOEXCEPT {
            return m_roiCx_;
        }

        void roiCx(int32_t value) {
            m_roiCx_ = value;
        }

        int32_t& roiCy() OMG_NOEXCEPT {
            return m_roiCy_;
        }

        const int32_t& roiCy() const OMG_NOEXCEPT {
            return m_roiCy_;
        }

        void roiCy(int32_t value) {
            m_roiCy_ = value;
        }

        int32_t& roiDx() OMG_NOEXCEPT {
            return m_roiDx_;
        }

        const int32_t& roiDx() const OMG_NOEXCEPT {
            return m_roiDx_;
        }

        void roiDx(int32_t value) {
            m_roiDx_ = value;
        }

        int32_t& roiDy() OMG_NOEXCEPT {
            return m_roiDy_;
        }

        const int32_t& roiDy() const OMG_NOEXCEPT {
            return m_roiDy_;
        }

        void roiDy(int32_t value) {
            m_roiDy_ = value;
        }

        bool operator == (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const;
        bool operator != (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const;

        void swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) OMG_NOEXCEPT ;

      private:

        int32_t m_roiAx_;
        int32_t m_roiAy_;
        int32_t m_roiBx_;
        int32_t m_roiBy_;
        int32_t m_roiCx_;
        int32_t m_roiCy_;
        int32_t m_roiDx_;
        int32_t m_roiDy_;

    };

    inline void swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& a, roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< bool >;
    // std::vector<bool> requires this additional dll-export:
    template class NDDSUSERDllExport std::vector<unsigned int, std::allocator<bool> >;
    template class NDDSUSERDllExport std::vector< bool >;
    #endif
    class NDDSUSERDllExport leftRight {
      public:
        leftRight();

        leftRight(
            const ::rti::core::bounded_sequence< bool, 786432 >& left,
            const ::rti::core::bounded_sequence< bool, 786432 >& right);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        leftRight (leftRight&&) = default;
        leftRight& operator=(leftRight&&) = default;
        leftRight& operator=(const leftRight&) = default;
        leftRight(const leftRight&) = default;
        #else
        leftRight(leftRight&& other_) OMG_NOEXCEPT;  
        leftRight& operator=(leftRight&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< bool, 786432 >& left() OMG_NOEXCEPT {
            return m_left_;
        }

        const ::rti::core::bounded_sequence< bool, 786432 >& left() const OMG_NOEXCEPT {
            return m_left_;
        }

        void left(const ::rti::core::bounded_sequence< bool, 786432 >& value) {
            m_left_ = value;
        }

        ::rti::core::bounded_sequence< bool, 786432 >& right() OMG_NOEXCEPT {
            return m_right_;
        }

        const ::rti::core::bounded_sequence< bool, 786432 >& right() const OMG_NOEXCEPT {
            return m_right_;
        }

        void right(const ::rti::core::bounded_sequence< bool, 786432 >& value) {
            m_right_ = value;
        }

        bool operator == (const leftRight& other_) const;
        bool operator != (const leftRight& other_) const;

        void swap(leftRight& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< bool, 786432 > m_left_;
        ::rti::core::bounded_sequence< bool, 786432 > m_right_;

    };

    inline void swap(leftRight& a, leftRight& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const leftRight& sample);

} // namespace DdsJobWzskIprTrace  
namespace DdsJobWzskIprCorner {

    class NDDSUSERDllExport setNTarget_req {
      public:
        setNTarget_req();

        explicit setNTarget_req(
            uint32_t NTarget);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setNTarget_req (setNTarget_req&&) = default;
        setNTarget_req& operator=(setNTarget_req&&) = default;
        setNTarget_req& operator=(const setNTarget_req&) = default;
        setNTarget_req(const setNTarget_req&) = default;
        #else
        setNTarget_req(setNTarget_req&& other_) OMG_NOEXCEPT;  
        setNTarget_req& operator=(setNTarget_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint32_t& NTarget() OMG_NOEXCEPT {
            return m_NTarget_;
        }

        const uint32_t& NTarget() const OMG_NOEXCEPT {
            return m_NTarget_;
        }

        void NTarget(uint32_t value) {
            m_NTarget_ = value;
        }

        bool operator == (const setNTarget_req& other_) const;
        bool operator != (const setNTarget_req& other_) const;

        void swap(setNTarget_req& other_) OMG_NOEXCEPT ;

      private:

        uint32_t m_NTarget_;

    };

    inline void swap(setNTarget_req& a, setNTarget_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setNTarget_req& sample);

    class NDDSUSERDllExport setNTarget_reply {
      public:
        setNTarget_reply();

        explicit setNTarget_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setNTarget_reply (setNTarget_reply&&) = default;
        setNTarget_reply& operator=(setNTarget_reply&&) = default;
        setNTarget_reply& operator=(const setNTarget_reply&) = default;
        setNTarget_reply(const setNTarget_reply&) = default;
        #else
        setNTarget_reply(setNTarget_reply&& other_) OMG_NOEXCEPT;  
        setNTarget_reply& operator=(setNTarget_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setNTarget_reply& other_) const;
        bool operator != (const setNTarget_reply& other_) const;

        void swap(setNTarget_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setNTarget_reply& a, setNTarget_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setNTarget_reply& sample);

    class NDDSUSERDllExport setRoi_req {
      public:
        setRoi_req();

        setRoi_req(
            int32_t roiAx,
            int32_t roiAy,
            int32_t roiBx,
            int32_t roiBy,
            int32_t roiCx,
            int32_t roiCy,
            int32_t roiDx,
            int32_t roiDy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoi_req (setRoi_req&&) = default;
        setRoi_req& operator=(setRoi_req&&) = default;
        setRoi_req& operator=(const setRoi_req&) = default;
        setRoi_req(const setRoi_req&) = default;
        #else
        setRoi_req(setRoi_req&& other_) OMG_NOEXCEPT;  
        setRoi_req& operator=(setRoi_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t& roiAx() OMG_NOEXCEPT {
            return m_roiAx_;
        }

        const int32_t& roiAx() const OMG_NOEXCEPT {
            return m_roiAx_;
        }

        void roiAx(int32_t value) {
            m_roiAx_ = value;
        }

        int32_t& roiAy() OMG_NOEXCEPT {
            return m_roiAy_;
        }

        const int32_t& roiAy() const OMG_NOEXCEPT {
            return m_roiAy_;
        }

        void roiAy(int32_t value) {
            m_roiAy_ = value;
        }

        int32_t& roiBx() OMG_NOEXCEPT {
            return m_roiBx_;
        }

        const int32_t& roiBx() const OMG_NOEXCEPT {
            return m_roiBx_;
        }

        void roiBx(int32_t value) {
            m_roiBx_ = value;
        }

        int32_t& roiBy() OMG_NOEXCEPT {
            return m_roiBy_;
        }

        const int32_t& roiBy() const OMG_NOEXCEPT {
            return m_roiBy_;
        }

        void roiBy(int32_t value) {
            m_roiBy_ = value;
        }

        int32_t& roiCx() OMG_NOEXCEPT {
            return m_roiCx_;
        }

        const int32_t& roiCx() const OMG_NOEXCEPT {
            return m_roiCx_;
        }

        void roiCx(int32_t value) {
            m_roiCx_ = value;
        }

        int32_t& roiCy() OMG_NOEXCEPT {
            return m_roiCy_;
        }

        const int32_t& roiCy() const OMG_NOEXCEPT {
            return m_roiCy_;
        }

        void roiCy(int32_t value) {
            m_roiCy_ = value;
        }

        int32_t& roiDx() OMG_NOEXCEPT {
            return m_roiDx_;
        }

        const int32_t& roiDx() const OMG_NOEXCEPT {
            return m_roiDx_;
        }

        void roiDx(int32_t value) {
            m_roiDx_ = value;
        }

        int32_t& roiDy() OMG_NOEXCEPT {
            return m_roiDy_;
        }

        const int32_t& roiDy() const OMG_NOEXCEPT {
            return m_roiDy_;
        }

        void roiDy(int32_t value) {
            m_roiDy_ = value;
        }

        bool operator == (const setRoi_req& other_) const;
        bool operator != (const setRoi_req& other_) const;

        void swap(setRoi_req& other_) OMG_NOEXCEPT ;

      private:

        int32_t m_roiAx_;
        int32_t m_roiAy_;
        int32_t m_roiBx_;
        int32_t m_roiBy_;
        int32_t m_roiCx_;
        int32_t m_roiCy_;
        int32_t m_roiDx_;
        int32_t m_roiDy_;

    };

    inline void swap(setRoi_req& a, setRoi_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoi_req& sample);

    class NDDSUSERDllExport setRoi_reply {
      public:
        setRoi_reply();

        explicit setRoi_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoi_reply (setRoi_reply&&) = default;
        setRoi_reply& operator=(setRoi_reply&&) = default;
        setRoi_reply& operator=(const setRoi_reply&) = default;
        setRoi_reply(const setRoi_reply&) = default;
        #else
        setRoi_reply(setRoi_reply&& other_) OMG_NOEXCEPT;  
        setRoi_reply& operator=(setRoi_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setRoi_reply& other_) const;
        bool operator != (const setRoi_reply& other_) const;

        void swap(setRoi_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setRoi_reply& a, setRoi_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoi_reply& sample);

    class NDDSUSERDllExport setRoiNotFull_req {
      public:
        setRoiNotFull_req();

        explicit setRoiNotFull_req(
            bool roiNotFull);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoiNotFull_req (setRoiNotFull_req&&) = default;
        setRoiNotFull_req& operator=(setRoiNotFull_req&&) = default;
        setRoiNotFull_req& operator=(const setRoiNotFull_req&) = default;
        setRoiNotFull_req(const setRoiNotFull_req&) = default;
        #else
        setRoiNotFull_req(setRoiNotFull_req&& other_) OMG_NOEXCEPT;  
        setRoiNotFull_req& operator=(setRoiNotFull_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& roiNotFull() OMG_NOEXCEPT {
            return m_roiNotFull_;
        }

        const bool& roiNotFull() const OMG_NOEXCEPT {
            return m_roiNotFull_;
        }

        void roiNotFull(bool value) {
            m_roiNotFull_ = value;
        }

        bool operator == (const setRoiNotFull_req& other_) const;
        bool operator != (const setRoiNotFull_req& other_) const;

        void swap(setRoiNotFull_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_roiNotFull_;

    };

    inline void swap(setRoiNotFull_req& a, setRoiNotFull_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoiNotFull_req& sample);

    class NDDSUSERDllExport setRoiNotFull_reply {
      public:
        setRoiNotFull_reply();

        explicit setRoiNotFull_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRoiNotFull_reply (setRoiNotFull_reply&&) = default;
        setRoiNotFull_reply& operator=(setRoiNotFull_reply&&) = default;
        setRoiNotFull_reply& operator=(const setRoiNotFull_reply&) = default;
        setRoiNotFull_reply(const setRoiNotFull_reply&) = default;
        #else
        setRoiNotFull_reply(setRoiNotFull_reply&& other_) OMG_NOEXCEPT;  
        setRoiNotFull_reply& operator=(setRoiNotFull_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setRoiNotFull_reply& other_) const;
        bool operator != (const setRoiNotFull_reply& other_) const;

        void swap(setRoiNotFull_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setRoiNotFull_reply& a, setRoiNotFull_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRoiNotFull_reply& sample);

    class NDDSUSERDllExport NTarget {
      public:
        NTarget();

        explicit NTarget(
            uint32_t _NTarget);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NTarget (NTarget&&) = default;
        NTarget& operator=(NTarget&&) = default;
        NTarget& operator=(const NTarget&) = default;
        NTarget(const NTarget&) = default;
        #else
        NTarget(NTarget&& other_) OMG_NOEXCEPT;  
        NTarget& operator=(NTarget&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint32_t& _NTarget() OMG_NOEXCEPT {
            return m__NTarget_;
        }

        const uint32_t& _NTarget() const OMG_NOEXCEPT {
            return m__NTarget_;
        }

        void _NTarget(uint32_t value) {
            m__NTarget_ = value;
        }

        bool operator == (const NTarget& other_) const;
        bool operator != (const NTarget& other_) const;

        void swap(NTarget& other_) OMG_NOEXCEPT ;

      private:

        uint32_t m__NTarget_;

    };

    inline void swap(NTarget& a, NTarget& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NTarget& sample);

    class NDDSUSERDllExport roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy {
      public:
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy();

        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(
            int32_t roiAx,
            int32_t roiAy,
            int32_t roiBx,
            int32_t roiBy,
            int32_t roiCx,
            int32_t roiCy,
            int32_t roiDx,
            int32_t roiDy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy (roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&) = default;
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&) = default;
        #else
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&& other_) OMG_NOEXCEPT;  
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t& roiAx() OMG_NOEXCEPT {
            return m_roiAx_;
        }

        const int32_t& roiAx() const OMG_NOEXCEPT {
            return m_roiAx_;
        }

        void roiAx(int32_t value) {
            m_roiAx_ = value;
        }

        int32_t& roiAy() OMG_NOEXCEPT {
            return m_roiAy_;
        }

        const int32_t& roiAy() const OMG_NOEXCEPT {
            return m_roiAy_;
        }

        void roiAy(int32_t value) {
            m_roiAy_ = value;
        }

        int32_t& roiBx() OMG_NOEXCEPT {
            return m_roiBx_;
        }

        const int32_t& roiBx() const OMG_NOEXCEPT {
            return m_roiBx_;
        }

        void roiBx(int32_t value) {
            m_roiBx_ = value;
        }

        int32_t& roiBy() OMG_NOEXCEPT {
            return m_roiBy_;
        }

        const int32_t& roiBy() const OMG_NOEXCEPT {
            return m_roiBy_;
        }

        void roiBy(int32_t value) {
            m_roiBy_ = value;
        }

        int32_t& roiCx() OMG_NOEXCEPT {
            return m_roiCx_;
        }

        const int32_t& roiCx() const OMG_NOEXCEPT {
            return m_roiCx_;
        }

        void roiCx(int32_t value) {
            m_roiCx_ = value;
        }

        int32_t& roiCy() OMG_NOEXCEPT {
            return m_roiCy_;
        }

        const int32_t& roiCy() const OMG_NOEXCEPT {
            return m_roiCy_;
        }

        void roiCy(int32_t value) {
            m_roiCy_ = value;
        }

        int32_t& roiDx() OMG_NOEXCEPT {
            return m_roiDx_;
        }

        const int32_t& roiDx() const OMG_NOEXCEPT {
            return m_roiDx_;
        }

        void roiDx(int32_t value) {
            m_roiDx_ = value;
        }

        int32_t& roiDy() OMG_NOEXCEPT {
            return m_roiDy_;
        }

        const int32_t& roiDy() const OMG_NOEXCEPT {
            return m_roiDy_;
        }

        void roiDy(int32_t value) {
            m_roiDy_ = value;
        }

        bool operator == (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const;
        bool operator != (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const;

        void swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) OMG_NOEXCEPT ;

      private:

        int32_t m_roiAx_;
        int32_t m_roiAy_;
        int32_t m_roiBx_;
        int32_t m_roiBy_;
        int32_t m_roiCx_;
        int32_t m_roiCy_;
        int32_t m_roiDx_;
        int32_t m_roiDy_;

    };

    inline void swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& a, roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample);

    class NDDSUSERDllExport flg {
      public:
        flg();

        explicit flg(
            const ::rti::core::bounded_sequence< bool, 786432 >& _flg);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        flg (flg&&) = default;
        flg& operator=(flg&&) = default;
        flg& operator=(const flg&) = default;
        flg(const flg&) = default;
        #else
        flg(flg&& other_) OMG_NOEXCEPT;  
        flg& operator=(flg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< bool, 786432 >& _flg() OMG_NOEXCEPT {
            return m__flg_;
        }

        const ::rti::core::bounded_sequence< bool, 786432 >& _flg() const OMG_NOEXCEPT {
            return m__flg_;
        }

        void _flg(const ::rti::core::bounded_sequence< bool, 786432 >& value) {
            m__flg_ = value;
        }

        bool operator == (const flg& other_) const;
        bool operator != (const flg& other_) const;

        void swap(flg& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< bool, 786432 > m__flg_;

    };

    inline void swap(flg& a, flg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const flg& sample);

} // namespace DdsJobWzskIprCorner  
namespace DdsJobWzskActServo {

    class NDDSUSERDllExport moveto_req {
      public:
        moveto_req();

        explicit moveto_req(
            float target);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        moveto_req (moveto_req&&) = default;
        moveto_req& operator=(moveto_req&&) = default;
        moveto_req& operator=(const moveto_req&) = default;
        moveto_req(const moveto_req&) = default;
        #else
        moveto_req(moveto_req&& other_) OMG_NOEXCEPT;  
        moveto_req& operator=(moveto_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& target() OMG_NOEXCEPT {
            return m_target_;
        }

        const float& target() const OMG_NOEXCEPT {
            return m_target_;
        }

        void target(float value) {
            m_target_ = value;
        }

        bool operator == (const moveto_req& other_) const;
        bool operator != (const moveto_req& other_) const;

        void swap(moveto_req& other_) OMG_NOEXCEPT ;

      private:

        float m_target_;

    };

    inline void swap(moveto_req& a, moveto_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const moveto_req& sample);

    class NDDSUSERDllExport moveto_reply {
      public:
        moveto_reply();

        explicit moveto_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        moveto_reply (moveto_reply&&) = default;
        moveto_reply& operator=(moveto_reply&&) = default;
        moveto_reply& operator=(const moveto_reply&) = default;
        moveto_reply(const moveto_reply&) = default;
        #else
        moveto_reply(moveto_reply&& other_) OMG_NOEXCEPT;  
        moveto_reply& operator=(moveto_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const moveto_reply& other_) const;
        bool operator != (const moveto_reply& other_) const;

        void swap(moveto_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(moveto_reply& a, moveto_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const moveto_reply& sample);

    class NDDSUSERDllExport stop_req {
      public:
        stop_req();

        explicit stop_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_req (stop_req&&) = default;
        stop_req& operator=(stop_req&&) = default;
        stop_req& operator=(const stop_req&) = default;
        stop_req(const stop_req&) = default;
        #else
        stop_req(stop_req&& other_) OMG_NOEXCEPT;  
        stop_req& operator=(stop_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT {
            return m_dummy_;
        }

        const bool& dummy() const OMG_NOEXCEPT {
            return m_dummy_;
        }

        void dummy(bool value) {
            m_dummy_ = value;
        }

        bool operator == (const stop_req& other_) const;
        bool operator != (const stop_req& other_) const;

        void swap(stop_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(stop_req& a, stop_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_req& sample);

    class NDDSUSERDllExport stop_reply {
      public:
        stop_reply();

        explicit stop_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        stop_reply (stop_reply&&) = default;
        stop_reply& operator=(stop_reply&&) = default;
        stop_reply& operator=(const stop_reply&) = default;
        stop_reply(const stop_reply&) = default;
        #else
        stop_reply(stop_reply&& other_) OMG_NOEXCEPT;  
        stop_reply& operator=(stop_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const stop_reply& other_) const;
        bool operator != (const stop_reply& other_) const;

        void swap(stop_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(stop_reply& a, stop_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const stop_reply& sample);

    class NDDSUSERDllExport turn_req {
      public:
        turn_req();

        explicit turn_req(
            bool ccwNotCw);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        turn_req (turn_req&&) = default;
        turn_req& operator=(turn_req&&) = default;
        turn_req& operator=(const turn_req&) = default;
        turn_req(const turn_req&) = default;
        #else
        turn_req(turn_req&& other_) OMG_NOEXCEPT;  
        turn_req& operator=(turn_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& ccwNotCw() OMG_NOEXCEPT {
            return m_ccwNotCw_;
        }

        const bool& ccwNotCw() const OMG_NOEXCEPT {
            return m_ccwNotCw_;
        }

        void ccwNotCw(bool value) {
            m_ccwNotCw_ = value;
        }

        bool operator == (const turn_req& other_) const;
        bool operator != (const turn_req& other_) const;

        void swap(turn_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_ccwNotCw_;

    };

    inline void swap(turn_req& a, turn_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const turn_req& sample);

    class NDDSUSERDllExport turn_reply {
      public:
        turn_reply();

        explicit turn_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        turn_reply (turn_reply&&) = default;
        turn_reply& operator=(turn_reply&&) = default;
        turn_reply& operator=(const turn_reply&) = default;
        turn_reply(const turn_reply&) = default;
        #else
        turn_reply(turn_reply&& other_) OMG_NOEXCEPT;  
        turn_reply& operator=(turn_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const turn_reply& other_) const;
        bool operator != (const turn_reply& other_) const;

        void swap(turn_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(turn_reply& a, turn_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const turn_reply& sample);

    class NDDSUSERDllExport zero_req {
      public:
        zero_req();

        explicit zero_req(
            bool dummy);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        zero_req (zero_req&&) = default;
        zero_req& operator=(zero_req&&) = default;
        zero_req& operator=(const zero_req&) = default;
        zero_req(const zero_req&) = default;
        #else
        zero_req(zero_req&& other_) OMG_NOEXCEPT;  
        zero_req& operator=(zero_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& dummy() OMG_NOEXCEPT {
            return m_dummy_;
        }

        const bool& dummy() const OMG_NOEXCEPT {
            return m_dummy_;
        }

        void dummy(bool value) {
            m_dummy_ = value;
        }

        bool operator == (const zero_req& other_) const;
        bool operator != (const zero_req& other_) const;

        void swap(zero_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_dummy_;

    };

    inline void swap(zero_req& a, zero_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const zero_req& sample);

    class NDDSUSERDllExport zero_reply {
      public:
        zero_reply();

        explicit zero_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        zero_reply (zero_reply&&) = default;
        zero_reply& operator=(zero_reply&&) = default;
        zero_reply& operator=(const zero_reply&) = default;
        zero_reply(const zero_reply&) = default;
        #else
        zero_reply(zero_reply&& other_) OMG_NOEXCEPT;  
        zero_reply& operator=(zero_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const zero_reply& other_) const;
        bool operator != (const zero_reply& other_) const;

        void swap(zero_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(zero_reply& a, zero_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const zero_reply& sample);

    class NDDSUSERDllExport angleTarget {
      public:
        angleTarget();

        angleTarget(
            float angle,
            float target);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        angleTarget (angleTarget&&) = default;
        angleTarget& operator=(angleTarget&&) = default;
        angleTarget& operator=(const angleTarget&) = default;
        angleTarget(const angleTarget&) = default;
        #else
        angleTarget(angleTarget&& other_) OMG_NOEXCEPT;  
        angleTarget& operator=(angleTarget&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& angle() OMG_NOEXCEPT {
            return m_angle_;
        }

        const float& angle() const OMG_NOEXCEPT {
            return m_angle_;
        }

        void angle(float value) {
            m_angle_ = value;
        }

        float& target() OMG_NOEXCEPT {
            return m_target_;
        }

        const float& target() const OMG_NOEXCEPT {
            return m_target_;
        }

        void target(float value) {
            m_target_ = value;
        }

        bool operator == (const angleTarget& other_) const;
        bool operator != (const angleTarget& other_) const;

        void swap(angleTarget& other_) OMG_NOEXCEPT ;

      private:

        float m_angle_;
        float m_target_;

    };

    inline void swap(angleTarget& a, angleTarget& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const angleTarget& sample);

} // namespace DdsJobWzskActServo  
namespace DdsJobWzskActLaser {

    class NDDSUSERDllExport setLeft_req {
      public:
        setLeft_req();

        explicit setLeft_req(
            float left);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setLeft_req (setLeft_req&&) = default;
        setLeft_req& operator=(setLeft_req&&) = default;
        setLeft_req& operator=(const setLeft_req&) = default;
        setLeft_req(const setLeft_req&) = default;
        #else
        setLeft_req(setLeft_req&& other_) OMG_NOEXCEPT;  
        setLeft_req& operator=(setLeft_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& left() OMG_NOEXCEPT {
            return m_left_;
        }

        const float& left() const OMG_NOEXCEPT {
            return m_left_;
        }

        void left(float value) {
            m_left_ = value;
        }

        bool operator == (const setLeft_req& other_) const;
        bool operator != (const setLeft_req& other_) const;

        void swap(setLeft_req& other_) OMG_NOEXCEPT ;

      private:

        float m_left_;

    };

    inline void swap(setLeft_req& a, setLeft_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setLeft_req& sample);

    class NDDSUSERDllExport setLeft_reply {
      public:
        setLeft_reply();

        explicit setLeft_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setLeft_reply (setLeft_reply&&) = default;
        setLeft_reply& operator=(setLeft_reply&&) = default;
        setLeft_reply& operator=(const setLeft_reply&) = default;
        setLeft_reply(const setLeft_reply&) = default;
        #else
        setLeft_reply(setLeft_reply&& other_) OMG_NOEXCEPT;  
        setLeft_reply& operator=(setLeft_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setLeft_reply& other_) const;
        bool operator != (const setLeft_reply& other_) const;

        void swap(setLeft_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setLeft_reply& a, setLeft_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setLeft_reply& sample);

    class NDDSUSERDllExport setRight_req {
      public:
        setRight_req();

        explicit setRight_req(
            float right);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRight_req (setRight_req&&) = default;
        setRight_req& operator=(setRight_req&&) = default;
        setRight_req& operator=(const setRight_req&) = default;
        setRight_req(const setRight_req&) = default;
        #else
        setRight_req(setRight_req&& other_) OMG_NOEXCEPT;  
        setRight_req& operator=(setRight_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& right() OMG_NOEXCEPT {
            return m_right_;
        }

        const float& right() const OMG_NOEXCEPT {
            return m_right_;
        }

        void right(float value) {
            m_right_ = value;
        }

        bool operator == (const setRight_req& other_) const;
        bool operator != (const setRight_req& other_) const;

        void swap(setRight_req& other_) OMG_NOEXCEPT ;

      private:

        float m_right_;

    };

    inline void swap(setRight_req& a, setRight_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRight_req& sample);

    class NDDSUSERDllExport setRight_reply {
      public:
        setRight_reply();

        explicit setRight_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setRight_reply (setRight_reply&&) = default;
        setRight_reply& operator=(setRight_reply&&) = default;
        setRight_reply& operator=(const setRight_reply&) = default;
        setRight_reply(const setRight_reply&) = default;
        #else
        setRight_reply(setRight_reply&& other_) OMG_NOEXCEPT;  
        setRight_reply& operator=(setRight_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setRight_reply& other_) const;
        bool operator != (const setRight_reply& other_) const;

        void swap(setRight_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setRight_reply& a, setRight_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setRight_reply& sample);

    class NDDSUSERDllExport leftRight {
      public:
        leftRight();

        leftRight(
            float left,
            float right);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        leftRight (leftRight&&) = default;
        leftRight& operator=(leftRight&&) = default;
        leftRight& operator=(const leftRight&) = default;
        leftRight(const leftRight&) = default;
        #else
        leftRight(leftRight&& other_) OMG_NOEXCEPT;  
        leftRight& operator=(leftRight&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& left() OMG_NOEXCEPT {
            return m_left_;
        }

        const float& left() const OMG_NOEXCEPT {
            return m_left_;
        }

        void left(float value) {
            m_left_ = value;
        }

        float& right() OMG_NOEXCEPT {
            return m_right_;
        }

        const float& right() const OMG_NOEXCEPT {
            return m_right_;
        }

        void right(float value) {
            m_right_ = value;
        }

        bool operator == (const leftRight& other_) const;
        bool operator != (const leftRight& other_) const;

        void swap(leftRight& other_) OMG_NOEXCEPT ;

      private:

        float m_left_;
        float m_right_;

    };

    inline void swap(leftRight& a, leftRight& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const leftRight& sample);

} // namespace DdsJobWzskActLaser  
namespace DdsJobWzskActExposure {

    class NDDSUSERDllExport setExposure_req {
      public:
        setExposure_req();

        setExposure_req(
            bool autoNotManual,
            float Texp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setExposure_req (setExposure_req&&) = default;
        setExposure_req& operator=(setExposure_req&&) = default;
        setExposure_req& operator=(const setExposure_req&) = default;
        setExposure_req(const setExposure_req&) = default;
        #else
        setExposure_req(setExposure_req&& other_) OMG_NOEXCEPT;  
        setExposure_req& operator=(setExposure_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& autoNotManual() OMG_NOEXCEPT {
            return m_autoNotManual_;
        }

        const bool& autoNotManual() const OMG_NOEXCEPT {
            return m_autoNotManual_;
        }

        void autoNotManual(bool value) {
            m_autoNotManual_ = value;
        }

        float& Texp() OMG_NOEXCEPT {
            return m_Texp_;
        }

        const float& Texp() const OMG_NOEXCEPT {
            return m_Texp_;
        }

        void Texp(float value) {
            m_Texp_ = value;
        }

        bool operator == (const setExposure_req& other_) const;
        bool operator != (const setExposure_req& other_) const;

        void swap(setExposure_req& other_) OMG_NOEXCEPT ;

      private:

        bool m_autoNotManual_;
        float m_Texp_;

    };

    inline void swap(setExposure_req& a, setExposure_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setExposure_req& sample);

    class NDDSUSERDllExport setExposure_reply {
      public:
        setExposure_reply();

        explicit setExposure_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setExposure_reply (setExposure_reply&&) = default;
        setExposure_reply& operator=(setExposure_reply&&) = default;
        setExposure_reply& operator=(const setExposure_reply&) = default;
        setExposure_reply(const setExposure_reply&) = default;
        #else
        setExposure_reply(setExposure_reply&& other_) OMG_NOEXCEPT;  
        setExposure_reply& operator=(setExposure_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setExposure_reply& other_) const;
        bool operator != (const setExposure_reply& other_) const;

        void swap(setExposure_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setExposure_reply& a, setExposure_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setExposure_reply& sample);

    class NDDSUSERDllExport setFocus_req {
      public:
        setFocus_req();

        explicit setFocus_req(
            float focus);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_req (setFocus_req&&) = default;
        setFocus_req& operator=(setFocus_req&&) = default;
        setFocus_req& operator=(const setFocus_req&) = default;
        setFocus_req(const setFocus_req&) = default;
        #else
        setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT;  
        setFocus_req& operator=(setFocus_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& focus() OMG_NOEXCEPT {
            return m_focus_;
        }

        const float& focus() const OMG_NOEXCEPT {
            return m_focus_;
        }

        void focus(float value) {
            m_focus_ = value;
        }

        bool operator == (const setFocus_req& other_) const;
        bool operator != (const setFocus_req& other_) const;

        void swap(setFocus_req& other_) OMG_NOEXCEPT ;

      private:

        float m_focus_;

    };

    inline void swap(setFocus_req& a, setFocus_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_req& sample);

    class NDDSUSERDllExport setFocus_reply {
      public:
        setFocus_reply();

        explicit setFocus_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setFocus_reply (setFocus_reply&&) = default;
        setFocus_reply& operator=(setFocus_reply&&) = default;
        setFocus_reply& operator=(const setFocus_reply&) = default;
        setFocus_reply(const setFocus_reply&) = default;
        #else
        setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT;  
        setFocus_reply& operator=(setFocus_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setFocus_reply& other_) const;
        bool operator != (const setFocus_reply& other_) const;

        void swap(setFocus_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setFocus_reply& a, setFocus_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setFocus_reply& sample);

    class NDDSUSERDllExport autoNotManualTexp {
      public:
        autoNotManualTexp();

        autoNotManualTexp(
            bool autoNotManual,
            float Texp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        autoNotManualTexp (autoNotManualTexp&&) = default;
        autoNotManualTexp& operator=(autoNotManualTexp&&) = default;
        autoNotManualTexp& operator=(const autoNotManualTexp&) = default;
        autoNotManualTexp(const autoNotManualTexp&) = default;
        #else
        autoNotManualTexp(autoNotManualTexp&& other_) OMG_NOEXCEPT;  
        autoNotManualTexp& operator=(autoNotManualTexp&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& autoNotManual() OMG_NOEXCEPT {
            return m_autoNotManual_;
        }

        const bool& autoNotManual() const OMG_NOEXCEPT {
            return m_autoNotManual_;
        }

        void autoNotManual(bool value) {
            m_autoNotManual_ = value;
        }

        float& Texp() OMG_NOEXCEPT {
            return m_Texp_;
        }

        const float& Texp() const OMG_NOEXCEPT {
            return m_Texp_;
        }

        void Texp(float value) {
            m_Texp_ = value;
        }

        bool operator == (const autoNotManualTexp& other_) const;
        bool operator != (const autoNotManualTexp& other_) const;

        void swap(autoNotManualTexp& other_) OMG_NOEXCEPT ;

      private:

        bool m_autoNotManual_;
        float m_Texp_;

    };

    inline void swap(autoNotManualTexp& a, autoNotManualTexp& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const autoNotManualTexp& sample);

    class NDDSUSERDllExport focus {
      public:
        focus();

        explicit focus(
            float _focus);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        focus (focus&&) = default;
        focus& operator=(focus&&) = default;
        focus& operator=(const focus&) = default;
        focus(const focus&) = default;
        #else
        focus(focus&& other_) OMG_NOEXCEPT;  
        focus& operator=(focus&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& _focus() OMG_NOEXCEPT {
            return m__focus_;
        }

        const float& _focus() const OMG_NOEXCEPT {
            return m__focus_;
        }

        void _focus(float value) {
            m__focus_ = value;
        }

        bool operator == (const focus& other_) const;
        bool operator != (const focus& other_) const;

        void swap(focus& other_) OMG_NOEXCEPT ;

      private:

        float m__focus_;

    };

    inline void swap(focus& a, focus& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const focus& sample);

} // namespace DdsJobWzskActExposure  
namespace DdsJobWzskAcqPtcloud {

    class NDDSUSERDllExport setDeltaTheta_req {
      public:
        setDeltaTheta_req();

        explicit setDeltaTheta_req(
            float deltaTheta);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setDeltaTheta_req (setDeltaTheta_req&&) = default;
        setDeltaTheta_req& operator=(setDeltaTheta_req&&) = default;
        setDeltaTheta_req& operator=(const setDeltaTheta_req&) = default;
        setDeltaTheta_req(const setDeltaTheta_req&) = default;
        #else
        setDeltaTheta_req(setDeltaTheta_req&& other_) OMG_NOEXCEPT;  
        setDeltaTheta_req& operator=(setDeltaTheta_req&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& deltaTheta() OMG_NOEXCEPT {
            return m_deltaTheta_;
        }

        const float& deltaTheta() const OMG_NOEXCEPT {
            return m_deltaTheta_;
        }

        void deltaTheta(float value) {
            m_deltaTheta_ = value;
        }

        bool operator == (const setDeltaTheta_req& other_) const;
        bool operator != (const setDeltaTheta_req& other_) const;

        void swap(setDeltaTheta_req& other_) OMG_NOEXCEPT ;

      private:

        float m_deltaTheta_;

    };

    inline void swap(setDeltaTheta_req& a, setDeltaTheta_req& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setDeltaTheta_req& sample);

    class NDDSUSERDllExport setDeltaTheta_reply {
      public:
        setDeltaTheta_reply();

        explicit setDeltaTheta_reply(
            bool success);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        setDeltaTheta_reply (setDeltaTheta_reply&&) = default;
        setDeltaTheta_reply& operator=(setDeltaTheta_reply&&) = default;
        setDeltaTheta_reply& operator=(const setDeltaTheta_reply&) = default;
        setDeltaTheta_reply(const setDeltaTheta_reply&) = default;
        #else
        setDeltaTheta_reply(setDeltaTheta_reply&& other_) OMG_NOEXCEPT;  
        setDeltaTheta_reply& operator=(setDeltaTheta_reply&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& success() OMG_NOEXCEPT {
            return m_success_;
        }

        const bool& success() const OMG_NOEXCEPT {
            return m_success_;
        }

        void success(bool value) {
            m_success_ = value;
        }

        bool operator == (const setDeltaTheta_reply& other_) const;
        bool operator != (const setDeltaTheta_reply& other_) const;

        void swap(setDeltaTheta_reply& other_) OMG_NOEXCEPT ;

      private:

        bool m_success_;

    };

    inline void swap(setDeltaTheta_reply& a, setDeltaTheta_reply& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const setDeltaTheta_reply& sample);

    class NDDSUSERDllExport deltaTheta {
      public:
        deltaTheta();

        explicit deltaTheta(
            float _deltaTheta);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        deltaTheta (deltaTheta&&) = default;
        deltaTheta& operator=(deltaTheta&&) = default;
        deltaTheta& operator=(const deltaTheta&) = default;
        deltaTheta(const deltaTheta&) = default;
        #else
        deltaTheta(deltaTheta&& other_) OMG_NOEXCEPT;  
        deltaTheta& operator=(deltaTheta&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        float& _deltaTheta() OMG_NOEXCEPT {
            return m__deltaTheta_;
        }

        const float& _deltaTheta() const OMG_NOEXCEPT {
            return m__deltaTheta_;
        }

        void _deltaTheta(float value) {
            m__deltaTheta_ = value;
        }

        bool operator == (const deltaTheta& other_) const;
        bool operator != (const deltaTheta& other_) const;

        void swap(deltaTheta& other_) OMG_NOEXCEPT ;

      private:

        float m__deltaTheta_;

    };

    inline void swap(deltaTheta& a, deltaTheta& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const deltaTheta& sample);

    class NDDSUSERDllExport xYZ {
      public:
        xYZ();

        xYZ(
            const ::rti::core::bounded_sequence< float, 72000 >& x,
            const ::rti::core::bounded_sequence< float, 72000 >& y,
            const ::rti::core::bounded_sequence< float, 72000 >& z);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        xYZ (xYZ&&) = default;
        xYZ& operator=(xYZ&&) = default;
        xYZ& operator=(const xYZ&) = default;
        xYZ(const xYZ&) = default;
        #else
        xYZ(xYZ&& other_) OMG_NOEXCEPT;  
        xYZ& operator=(xYZ&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< float, 72000 >& x() OMG_NOEXCEPT {
            return m_x_;
        }

        const ::rti::core::bounded_sequence< float, 72000 >& x() const OMG_NOEXCEPT {
            return m_x_;
        }

        void x(const ::rti::core::bounded_sequence< float, 72000 >& value) {
            m_x_ = value;
        }

        ::rti::core::bounded_sequence< float, 72000 >& y() OMG_NOEXCEPT {
            return m_y_;
        }

        const ::rti::core::bounded_sequence< float, 72000 >& y() const OMG_NOEXCEPT {
            return m_y_;
        }

        void y(const ::rti::core::bounded_sequence< float, 72000 >& value) {
            m_y_ = value;
        }

        ::rti::core::bounded_sequence< float, 72000 >& z() OMG_NOEXCEPT {
            return m_z_;
        }

        const ::rti::core::bounded_sequence< float, 72000 >& z() const OMG_NOEXCEPT {
            return m_z_;
        }

        void z(const ::rti::core::bounded_sequence< float, 72000 >& value) {
            m_z_ = value;
        }

        bool operator == (const xYZ& other_) const;
        bool operator != (const xYZ& other_) const;

        void swap(xYZ& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< float, 72000 > m_x_;
        ::rti::core::bounded_sequence< float, 72000 > m_y_;
        ::rti::core::bounded_sequence< float, 72000 > m_z_;

    };

    inline void swap(xYZ& a, xYZ& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const xYZ& sample);

} // namespace DdsJobWzskAcqPtcloud  
namespace DdsJobWzskAcqPreview {

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< uint8_t >;
    template class NDDSUSERDllExport std::vector< uint8_t >;
    #endif
    class NDDSUSERDllExport gray {
      public:
        gray();

        explicit gray(
            const ::rti::core::bounded_sequence< uint8_t, 49152 >& _gray);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        gray (gray&&) = default;
        gray& operator=(gray&&) = default;
        gray& operator=(const gray&) = default;
        gray(const gray&) = default;
        #else
        gray(gray&& other_) OMG_NOEXCEPT;  
        gray& operator=(gray&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< uint8_t, 49152 >& _gray() OMG_NOEXCEPT {
            return m__gray_;
        }

        const ::rti::core::bounded_sequence< uint8_t, 49152 >& _gray() const OMG_NOEXCEPT {
            return m__gray_;
        }

        void _gray(const ::rti::core::bounded_sequence< uint8_t, 49152 >& value) {
            m__gray_ = value;
        }

        bool operator == (const gray& other_) const;
        bool operator != (const gray& other_) const;

        void swap(gray& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< uint8_t, 49152 > m__gray_;

    };

    inline void swap(gray& a, gray& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const gray& sample);

    class NDDSUSERDllExport redGreenBlue {
      public:
        redGreenBlue();

        redGreenBlue(
            const ::rti::core::bounded_sequence< uint8_t, 19200 >& red,
            const ::rti::core::bounded_sequence< uint8_t, 19200 >& green,
            const ::rti::core::bounded_sequence< uint8_t, 19200 >& blue);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        redGreenBlue (redGreenBlue&&) = default;
        redGreenBlue& operator=(redGreenBlue&&) = default;
        redGreenBlue& operator=(const redGreenBlue&) = default;
        redGreenBlue(const redGreenBlue&) = default;
        #else
        redGreenBlue(redGreenBlue&& other_) OMG_NOEXCEPT;  
        redGreenBlue& operator=(redGreenBlue&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< uint8_t, 19200 >& red() OMG_NOEXCEPT {
            return m_red_;
        }

        const ::rti::core::bounded_sequence< uint8_t, 19200 >& red() const OMG_NOEXCEPT {
            return m_red_;
        }

        void red(const ::rti::core::bounded_sequence< uint8_t, 19200 >& value) {
            m_red_ = value;
        }

        ::rti::core::bounded_sequence< uint8_t, 19200 >& green() OMG_NOEXCEPT {
            return m_green_;
        }

        const ::rti::core::bounded_sequence< uint8_t, 19200 >& green() const OMG_NOEXCEPT {
            return m_green_;
        }

        void green(const ::rti::core::bounded_sequence< uint8_t, 19200 >& value) {
            m_green_ = value;
        }

        ::rti::core::bounded_sequence< uint8_t, 19200 >& blue() OMG_NOEXCEPT {
            return m_blue_;
        }

        const ::rti::core::bounded_sequence< uint8_t, 19200 >& blue() const OMG_NOEXCEPT {
            return m_blue_;
        }

        void blue(const ::rti::core::bounded_sequence< uint8_t, 19200 >& value) {
            m_blue_ = value;
        }

        bool operator == (const redGreenBlue& other_) const;
        bool operator != (const redGreenBlue& other_) const;

        void swap(redGreenBlue& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< uint8_t, 19200 > m_red_;
        ::rti::core::bounded_sequence< uint8_t, 19200 > m_green_;
        ::rti::core::bounded_sequence< uint8_t, 19200 > m_blue_;

    };

    inline void swap(redGreenBlue& a, redGreenBlue& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const redGreenBlue& sample);

} // namespace DdsJobWzskAcqPreview  

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< DdsFloatmat > {
            NDDSUSERDllExport static std::string value() {
                return "DdsFloatmat";
            }
        };

        template<>
        struct is_topic_type< DdsFloatmat > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsFloatmat > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsFloatmat& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsFloatmat& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsFloatmat& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsFloatmat& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsDoublemat > {
            NDDSUSERDllExport static std::string value() {
                return "DdsDoublemat";
            }
        };

        template<>
        struct is_topic_type< DdsDoublemat > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsDoublemat > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsDoublemat& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsDoublemat& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsDoublemat& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsDoublemat& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskSrcSysinfo::temp > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskSrcSysinfo::temp";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskSrcSysinfo::temp > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskSrcSysinfo::temp > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskSrcSysinfo::temp& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskSrcSysinfo::temp& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskSrcSysinfo::temp& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskSrcSysinfo::temp& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setLevel_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setLevel_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setLevel_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setLevel_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setLevel_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setLevel_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setLevel_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setLevel_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setLevel_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setLevel_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setLevel_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setLevel_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setLevel_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setLevel_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setLevel_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setLevel_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setRoi_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setRoi_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setRoi_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setRoi_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setRoi_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setRoi_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setRoi_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setRoi_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setRoi_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setRoi_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setRoi_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setRoi_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setRoi_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setRoi_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setRoi_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setRoi_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setRoiNotFull_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setRoiNotFull_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setRoiNotFull_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setRoiNotFull_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setRoiNotFull_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setRoiNotFull_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setRoiNotFull_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::setRoiNotFull_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::setRoiNotFull_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::setRoiNotFull_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::setRoiNotFull_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::setRoiNotFull_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::setRoiNotFull_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::setRoiNotFull_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::pOnLeftPOnRight > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::pOnLeftPOnRight";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::pOnLeftPOnRight > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::pOnLeftPOnRight& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::pOnLeftPOnRight& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::pOnLeftPOnRight& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::pOnLeftPOnRight& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::levelOnLevelOff > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::levelOnLevelOff";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::levelOnLevelOff > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::levelOnLevelOff& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::levelOnLevelOff& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::levelOnLevelOff& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::levelOnLevelOff& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprTrace::leftRight > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprTrace::leftRight";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprTrace::leftRight > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprTrace::leftRight > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprTrace::leftRight& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprTrace::leftRight& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprTrace::leftRight& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprTrace::leftRight& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setNTarget_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setNTarget_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setNTarget_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setNTarget_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setNTarget_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setNTarget_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setNTarget_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setNTarget_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setNTarget_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setNTarget_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setNTarget_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setNTarget_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setNTarget_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setNTarget_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setNTarget_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setNTarget_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setRoi_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setRoi_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setRoi_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setRoi_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setRoi_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setRoi_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setRoi_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setRoi_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setRoi_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setRoi_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setRoi_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setRoi_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setRoi_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setRoi_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setRoi_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setRoi_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setRoiNotFull_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setRoiNotFull_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setRoiNotFull_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setRoiNotFull_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setRoiNotFull_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setRoiNotFull_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setRoiNotFull_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::setRoiNotFull_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::setRoiNotFull_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::setRoiNotFull_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::setRoiNotFull_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::setRoiNotFull_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::setRoiNotFull_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::setRoiNotFull_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::NTarget > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::NTarget";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::NTarget > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::NTarget > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::NTarget& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::NTarget& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::NTarget& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::NTarget& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskIprCorner::flg > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskIprCorner::flg";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskIprCorner::flg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskIprCorner::flg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskIprCorner::flg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskIprCorner::flg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskIprCorner::flg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskIprCorner::flg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::moveto_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::moveto_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::moveto_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::moveto_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::moveto_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::moveto_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::moveto_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::moveto_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::moveto_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::moveto_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::moveto_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::moveto_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::moveto_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::moveto_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::moveto_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::moveto_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::stop_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::stop_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::stop_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::stop_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::stop_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::stop_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::stop_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::stop_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::stop_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::stop_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::stop_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::stop_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::stop_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::stop_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::stop_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::stop_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::turn_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::turn_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::turn_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::turn_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::turn_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::turn_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::turn_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::turn_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::turn_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::turn_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::turn_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::turn_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::turn_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::turn_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::turn_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::turn_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::zero_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::zero_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::zero_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::zero_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::zero_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::zero_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::zero_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::zero_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::zero_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::zero_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::zero_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::zero_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::zero_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::zero_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::zero_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::zero_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActServo::angleTarget > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActServo::angleTarget";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActServo::angleTarget > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActServo::angleTarget > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActServo::angleTarget& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActServo::angleTarget& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActServo::angleTarget& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActServo::angleTarget& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActLaser::setLeft_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActLaser::setLeft_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActLaser::setLeft_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActLaser::setLeft_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActLaser::setLeft_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActLaser::setLeft_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActLaser::setLeft_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActLaser::setLeft_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActLaser::setLeft_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActLaser::setLeft_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActLaser::setLeft_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActLaser::setLeft_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActLaser::setLeft_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActLaser::setLeft_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActLaser::setLeft_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActLaser::setLeft_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActLaser::setRight_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActLaser::setRight_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActLaser::setRight_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActLaser::setRight_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActLaser::setRight_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActLaser::setRight_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActLaser::setRight_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActLaser::setRight_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActLaser::setRight_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActLaser::setRight_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActLaser::setRight_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActLaser::setRight_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActLaser::setRight_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActLaser::setRight_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActLaser::setRight_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActLaser::setRight_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActLaser::leftRight > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActLaser::leftRight";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActLaser::leftRight > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActLaser::leftRight > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActLaser::leftRight& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActLaser::leftRight& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActLaser::leftRight& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActLaser::leftRight& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::setExposure_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::setExposure_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::setExposure_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::setExposure_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::setExposure_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::setExposure_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::setExposure_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::setExposure_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::setExposure_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::setExposure_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::setExposure_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::setExposure_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::setExposure_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::setExposure_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::setExposure_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::setExposure_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::setFocus_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::setFocus_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::setFocus_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::setFocus_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::setFocus_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::setFocus_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::setFocus_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::setFocus_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::setFocus_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::setFocus_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::setFocus_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::setFocus_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::setFocus_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::setFocus_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::setFocus_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::setFocus_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::autoNotManualTexp > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::autoNotManualTexp";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::autoNotManualTexp > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::autoNotManualTexp > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::autoNotManualTexp& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::autoNotManualTexp& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::autoNotManualTexp& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::autoNotManualTexp& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskActExposure::focus > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskActExposure::focus";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskActExposure::focus > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskActExposure::focus > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskActExposure::focus& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskActExposure::focus& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskActExposure::focus& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskActExposure::focus& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPtcloud::setDeltaTheta_req > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPtcloud::setDeltaTheta_req";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_req > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPtcloud::setDeltaTheta_reply";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPtcloud::deltaTheta > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPtcloud::deltaTheta";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPtcloud::deltaTheta > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPtcloud::deltaTheta& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPtcloud::deltaTheta& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPtcloud::deltaTheta& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPtcloud::deltaTheta& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPtcloud::xYZ > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPtcloud::xYZ";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPtcloud::xYZ > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPtcloud::xYZ > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPtcloud::xYZ& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPtcloud::xYZ& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPtcloud::xYZ& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPtcloud::xYZ& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPreview::gray > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPreview::gray";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPreview::gray > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPreview::gray > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPreview::gray& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPreview::gray& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPreview::gray& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPreview::gray& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DdsJobWzskAcqPreview::redGreenBlue > {
            NDDSUSERDllExport static std::string value() {
                return "DdsJobWzskAcqPreview::redGreenBlue";
            }
        };

        template<>
        struct is_topic_type< DdsJobWzskAcqPreview::redGreenBlue > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DdsJobWzskAcqPreview::redGreenBlue > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DdsJobWzskAcqPreview::redGreenBlue& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DdsJobWzskAcqPreview::redGreenBlue& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DdsJobWzskAcqPreview::redGreenBlue& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DdsJobWzskAcqPreview::redGreenBlue& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< tinyint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< utinyint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< smallint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< usmallint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< _cxx_int_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< uint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bigint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ubigint_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsFloatmat > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsFloatmat > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsDoublemat > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsDoublemat > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< stringvec_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< vecsref_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskSrcSysinfo::temp > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskSrcSysinfo::temp > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setLevel_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setLevel_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setLevel_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setLevel_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setRoi_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setRoi_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setRoi_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setRoi_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setRoiNotFull_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setRoiNotFull_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::setRoiNotFull_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::setRoiNotFull_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::pOnLeftPOnRight > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::pOnLeftPOnRight > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::levelOnLevelOff > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::levelOnLevelOff > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprTrace::leftRight > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprTrace::leftRight > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setNTarget_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setNTarget_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setNTarget_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setNTarget_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setRoi_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setRoi_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setRoi_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setRoi_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setRoiNotFull_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setRoiNotFull_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::setRoiNotFull_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::setRoiNotFull_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::NTarget > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::NTarget > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskIprCorner::flg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskIprCorner::flg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::moveto_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::moveto_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::moveto_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::moveto_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::stop_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::stop_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::stop_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::stop_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::turn_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::turn_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::turn_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::turn_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::zero_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::zero_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::zero_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::zero_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActServo::angleTarget > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActServo::angleTarget > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActLaser::setLeft_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActLaser::setLeft_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActLaser::setLeft_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActLaser::setLeft_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActLaser::setRight_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActLaser::setRight_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActLaser::setRight_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActLaser::setRight_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActLaser::leftRight > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActLaser::leftRight > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::setExposure_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::setExposure_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::setExposure_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::setExposure_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::setFocus_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::setFocus_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::setFocus_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::setFocus_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::autoNotManualTexp > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::autoNotManualTexp > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskActExposure::focus > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskActExposure::focus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_req > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPtcloud::setDeltaTheta_req > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPtcloud::deltaTheta > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPtcloud::deltaTheta > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPtcloud::xYZ > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPtcloud::xYZ > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPreview::gray > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPreview::gray > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DdsJobWzskAcqPreview::redGreenBlue > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DdsJobWzskAcqPreview::redGreenBlue > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // DdsWzsk_509372353_hpp

