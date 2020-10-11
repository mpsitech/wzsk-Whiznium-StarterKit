

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsWzsk.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "DdsWzsk.hpp"
#include "DdsWzskPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- DdsFloatmat: 

DdsFloatmat::DdsFloatmat() :
    m_M_ (0u) ,
    m_N_ (0u)  {
}   

DdsFloatmat::DdsFloatmat (
    const ::rti::core::bounded_sequence< float, 100 >& vec,
    uint32_t M,
    uint32_t N)
    :
        m_vec_( vec ),
        m_M_( M ),
        m_N_( N ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DdsFloatmat::DdsFloatmat(DdsFloatmat&& other_) OMG_NOEXCEPT  :m_vec_ (std::move(other_.m_vec_))
,
m_M_ (std::move(other_.m_M_))
,
m_N_ (std::move(other_.m_N_))
{
} 

DdsFloatmat& DdsFloatmat::operator=(DdsFloatmat&&  other_) OMG_NOEXCEPT {
    DdsFloatmat tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DdsFloatmat::swap(DdsFloatmat& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_vec_, other_.m_vec_);
    swap(m_M_, other_.m_M_);
    swap(m_N_, other_.m_N_);
}  

bool DdsFloatmat::operator == (const DdsFloatmat& other_) const {
    if (m_vec_ != other_.m_vec_) {
        return false;
    }
    if (m_M_ != other_.m_M_) {
        return false;
    }
    if (m_N_ != other_.m_N_) {
        return false;
    }
    return true;
}
bool DdsFloatmat::operator != (const DdsFloatmat& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DdsFloatmat& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "vec: " << sample.vec()<<", ";
    o << "M: " << sample.M()<<", ";
    o << "N: " << sample.N() ;
    o <<"]";
    return o;
}

// ---- DdsDoublemat: 

DdsDoublemat::DdsDoublemat() :
    m_M_ (0u) ,
    m_N_ (0u)  {
}   

DdsDoublemat::DdsDoublemat (
    const ::rti::core::bounded_sequence< double, 100 >& vec,
    uint32_t M,
    uint32_t N)
    :
        m_vec_( vec ),
        m_M_( M ),
        m_N_( N ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DdsDoublemat::DdsDoublemat(DdsDoublemat&& other_) OMG_NOEXCEPT  :m_vec_ (std::move(other_.m_vec_))
,
m_M_ (std::move(other_.m_M_))
,
m_N_ (std::move(other_.m_N_))
{
} 

DdsDoublemat& DdsDoublemat::operator=(DdsDoublemat&&  other_) OMG_NOEXCEPT {
    DdsDoublemat tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DdsDoublemat::swap(DdsDoublemat& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_vec_, other_.m_vec_);
    swap(m_M_, other_.m_M_);
    swap(m_N_, other_.m_N_);
}  

bool DdsDoublemat::operator == (const DdsDoublemat& other_) const {
    if (m_vec_ != other_.m_vec_) {
        return false;
    }
    if (m_M_ != other_.m_M_) {
        return false;
    }
    if (m_N_ != other_.m_N_) {
        return false;
    }
    return true;
}
bool DdsDoublemat::operator != (const DdsDoublemat& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DdsDoublemat& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "vec: " << sample.vec()<<", ";
    o << "M: " << sample.M()<<", ";
    o << "N: " << sample.N() ;
    o <<"]";
    return o;
}

namespace DdsJobWzskSrcSysinfo {

    // ---- loadAllLoadCore0LoadCore1LoadCore2LoadCore3: 

    loadAllLoadCore0LoadCore1LoadCore2LoadCore3::loadAllLoadCore0LoadCore1LoadCore2LoadCore3()  {
    }   

    loadAllLoadCore0LoadCore1LoadCore2LoadCore3::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 (
        const ::rti::core::bounded_sequence< float, 60 >& loadAll,
        const ::rti::core::bounded_sequence< float, 60 >& loadCore0,
        const ::rti::core::bounded_sequence< float, 60 >& loadCore1,
        const ::rti::core::bounded_sequence< float, 60 >& loadCore2,
        const ::rti::core::bounded_sequence< float, 60 >& loadCore3)
        :
            m_loadAll_( loadAll ),
            m_loadCore0_( loadCore0 ),
            m_loadCore1_( loadCore1 ),
            m_loadCore2_( loadCore2 ),
            m_loadCore3_( loadCore3 ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3::loadAllLoadCore0LoadCore1LoadCore2LoadCore3(loadAllLoadCore0LoadCore1LoadCore2LoadCore3&& other_) OMG_NOEXCEPT  :m_loadAll_ (std::move(other_.m_loadAll_))
    ,
    m_loadCore0_ (std::move(other_.m_loadCore0_))
    ,
    m_loadCore1_ (std::move(other_.m_loadCore1_))
    ,
    m_loadCore2_ (std::move(other_.m_loadCore2_))
    ,
    m_loadCore3_ (std::move(other_.m_loadCore3_))
    {
    } 

    loadAllLoadCore0LoadCore1LoadCore2LoadCore3& loadAllLoadCore0LoadCore1LoadCore2LoadCore3::operator=(loadAllLoadCore0LoadCore1LoadCore2LoadCore3&&  other_) OMG_NOEXCEPT {
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void loadAllLoadCore0LoadCore1LoadCore2LoadCore3::swap(loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_loadAll_, other_.m_loadAll_);
        swap(m_loadCore0_, other_.m_loadCore0_);
        swap(m_loadCore1_, other_.m_loadCore1_);
        swap(m_loadCore2_, other_.m_loadCore2_);
        swap(m_loadCore3_, other_.m_loadCore3_);
    }  

    bool loadAllLoadCore0LoadCore1LoadCore2LoadCore3::operator == (const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_) const {
        if (m_loadAll_ != other_.m_loadAll_) {
            return false;
        }
        if (m_loadCore0_ != other_.m_loadCore0_) {
            return false;
        }
        if (m_loadCore1_ != other_.m_loadCore1_) {
            return false;
        }
        if (m_loadCore2_ != other_.m_loadCore2_) {
            return false;
        }
        if (m_loadCore3_ != other_.m_loadCore3_) {
            return false;
        }
        return true;
    }
    bool loadAllLoadCore0LoadCore1LoadCore2LoadCore3::operator != (const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "loadAll: " << sample.loadAll()<<", ";
        o << "loadCore0: " << sample.loadCore0()<<", ";
        o << "loadCore1: " << sample.loadCore1()<<", ";
        o << "loadCore2: " << sample.loadCore2()<<", ";
        o << "loadCore3: " << sample.loadCore3() ;
        o <<"]";
        return o;
    }

    // ---- temp: 

    temp::temp()  {
    }   

    temp::temp (
        const ::rti::core::bounded_sequence< float, 60 >& _temp)
        :
            m__temp_( _temp ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    temp::temp(temp&& other_) OMG_NOEXCEPT  :m__temp_ (std::move(other_.m__temp_))
    {
    } 

    temp& temp::operator=(temp&&  other_) OMG_NOEXCEPT {
        temp tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void temp::swap(temp& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m__temp_, other_.m__temp_);
    }  

    bool temp::operator == (const temp& other_) const {
        if (m__temp_ != other_.m__temp_) {
            return false;
        }
        return true;
    }
    bool temp::operator != (const temp& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const temp& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "_temp: " << sample._temp() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskSrcSysinfo  

namespace DdsJobWzskIprTrace {

    // ---- setLevel_req: 

    setLevel_req::setLevel_req() :
        m_levelOn_ (0) ,
        m_levelOff_ (0)  {
    }   

    setLevel_req::setLevel_req (
        uint8_t levelOn,
        uint8_t levelOff)
        :
            m_levelOn_( levelOn ),
            m_levelOff_( levelOff ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setLevel_req::setLevel_req(setLevel_req&& other_) OMG_NOEXCEPT  :m_levelOn_ (std::move(other_.m_levelOn_))
    ,
    m_levelOff_ (std::move(other_.m_levelOff_))
    {
    } 

    setLevel_req& setLevel_req::operator=(setLevel_req&&  other_) OMG_NOEXCEPT {
        setLevel_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setLevel_req::swap(setLevel_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_levelOn_, other_.m_levelOn_);
        swap(m_levelOff_, other_.m_levelOff_);
    }  

    bool setLevel_req::operator == (const setLevel_req& other_) const {
        if (m_levelOn_ != other_.m_levelOn_) {
            return false;
        }
        if (m_levelOff_ != other_.m_levelOff_) {
            return false;
        }
        return true;
    }
    bool setLevel_req::operator != (const setLevel_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setLevel_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "levelOn: <" << std::hex<<(int)sample.levelOn() <<", ";
        o << "levelOff: <" << std::hex<<(int)sample.levelOff()  ;
        o <<"]";
        return o;
    }

    // ---- setLevel_reply: 

    setLevel_reply::setLevel_reply() :
        m_success_ (0)  {
    }   

    setLevel_reply::setLevel_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setLevel_reply::setLevel_reply(setLevel_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setLevel_reply& setLevel_reply::operator=(setLevel_reply&&  other_) OMG_NOEXCEPT {
        setLevel_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setLevel_reply::swap(setLevel_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setLevel_reply::operator == (const setLevel_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setLevel_reply::operator != (const setLevel_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setLevel_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setRoi_req: 

    setRoi_req::setRoi_req() :
        m_roiAx_ (0) ,
        m_roiAy_ (0) ,
        m_roiBx_ (0) ,
        m_roiBy_ (0) ,
        m_roiCx_ (0) ,
        m_roiCy_ (0) ,
        m_roiDx_ (0) ,
        m_roiDy_ (0)  {
    }   

    setRoi_req::setRoi_req (
        int32_t roiAx,
        int32_t roiAy,
        int32_t roiBx,
        int32_t roiBy,
        int32_t roiCx,
        int32_t roiCy,
        int32_t roiDx,
        int32_t roiDy)
        :
            m_roiAx_( roiAx ),
            m_roiAy_( roiAy ),
            m_roiBx_( roiBx ),
            m_roiBy_( roiBy ),
            m_roiCx_( roiCx ),
            m_roiCy_( roiCy ),
            m_roiDx_( roiDx ),
            m_roiDy_( roiDy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoi_req::setRoi_req(setRoi_req&& other_) OMG_NOEXCEPT  :m_roiAx_ (std::move(other_.m_roiAx_))
    ,
    m_roiAy_ (std::move(other_.m_roiAy_))
    ,
    m_roiBx_ (std::move(other_.m_roiBx_))
    ,
    m_roiBy_ (std::move(other_.m_roiBy_))
    ,
    m_roiCx_ (std::move(other_.m_roiCx_))
    ,
    m_roiCy_ (std::move(other_.m_roiCy_))
    ,
    m_roiDx_ (std::move(other_.m_roiDx_))
    ,
    m_roiDy_ (std::move(other_.m_roiDy_))
    {
    } 

    setRoi_req& setRoi_req::operator=(setRoi_req&&  other_) OMG_NOEXCEPT {
        setRoi_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoi_req::swap(setRoi_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiAx_, other_.m_roiAx_);
        swap(m_roiAy_, other_.m_roiAy_);
        swap(m_roiBx_, other_.m_roiBx_);
        swap(m_roiBy_, other_.m_roiBy_);
        swap(m_roiCx_, other_.m_roiCx_);
        swap(m_roiCy_, other_.m_roiCy_);
        swap(m_roiDx_, other_.m_roiDx_);
        swap(m_roiDy_, other_.m_roiDy_);
    }  

    bool setRoi_req::operator == (const setRoi_req& other_) const {
        if (m_roiAx_ != other_.m_roiAx_) {
            return false;
        }
        if (m_roiAy_ != other_.m_roiAy_) {
            return false;
        }
        if (m_roiBx_ != other_.m_roiBx_) {
            return false;
        }
        if (m_roiBy_ != other_.m_roiBy_) {
            return false;
        }
        if (m_roiCx_ != other_.m_roiCx_) {
            return false;
        }
        if (m_roiCy_ != other_.m_roiCy_) {
            return false;
        }
        if (m_roiDx_ != other_.m_roiDx_) {
            return false;
        }
        if (m_roiDy_ != other_.m_roiDy_) {
            return false;
        }
        return true;
    }
    bool setRoi_req::operator != (const setRoi_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoi_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiAx: " << sample.roiAx()<<", ";
        o << "roiAy: " << sample.roiAy()<<", ";
        o << "roiBx: " << sample.roiBx()<<", ";
        o << "roiBy: " << sample.roiBy()<<", ";
        o << "roiCx: " << sample.roiCx()<<", ";
        o << "roiCy: " << sample.roiCy()<<", ";
        o << "roiDx: " << sample.roiDx()<<", ";
        o << "roiDy: " << sample.roiDy() ;
        o <<"]";
        return o;
    }

    // ---- setRoi_reply: 

    setRoi_reply::setRoi_reply() :
        m_success_ (0)  {
    }   

    setRoi_reply::setRoi_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoi_reply::setRoi_reply(setRoi_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setRoi_reply& setRoi_reply::operator=(setRoi_reply&&  other_) OMG_NOEXCEPT {
        setRoi_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoi_reply::swap(setRoi_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setRoi_reply::operator == (const setRoi_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setRoi_reply::operator != (const setRoi_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoi_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setRoiNotFull_req: 

    setRoiNotFull_req::setRoiNotFull_req() :
        m_roiNotFull_ (0)  {
    }   

    setRoiNotFull_req::setRoiNotFull_req (
        bool roiNotFull)
        :
            m_roiNotFull_( roiNotFull ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoiNotFull_req::setRoiNotFull_req(setRoiNotFull_req&& other_) OMG_NOEXCEPT  :m_roiNotFull_ (std::move(other_.m_roiNotFull_))
    {
    } 

    setRoiNotFull_req& setRoiNotFull_req::operator=(setRoiNotFull_req&&  other_) OMG_NOEXCEPT {
        setRoiNotFull_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoiNotFull_req::swap(setRoiNotFull_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiNotFull_, other_.m_roiNotFull_);
    }  

    bool setRoiNotFull_req::operator == (const setRoiNotFull_req& other_) const {
        if (m_roiNotFull_ != other_.m_roiNotFull_) {
            return false;
        }
        return true;
    }
    bool setRoiNotFull_req::operator != (const setRoiNotFull_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoiNotFull_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiNotFull: " << sample.roiNotFull() ;
        o <<"]";
        return o;
    }

    // ---- setRoiNotFull_reply: 

    setRoiNotFull_reply::setRoiNotFull_reply() :
        m_success_ (0)  {
    }   

    setRoiNotFull_reply::setRoiNotFull_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoiNotFull_reply::setRoiNotFull_reply(setRoiNotFull_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setRoiNotFull_reply& setRoiNotFull_reply::operator=(setRoiNotFull_reply&&  other_) OMG_NOEXCEPT {
        setRoiNotFull_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoiNotFull_reply::swap(setRoiNotFull_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setRoiNotFull_reply::operator == (const setRoiNotFull_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setRoiNotFull_reply::operator != (const setRoiNotFull_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoiNotFull_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- pOnLeftPOnRight: 

    pOnLeftPOnRight::pOnLeftPOnRight() :
        m_pOnLeft_ (0.0f) ,
        m_pOnRight_ (0.0f)  {
    }   

    pOnLeftPOnRight::pOnLeftPOnRight (
        float pOnLeft,
        float pOnRight)
        :
            m_pOnLeft_( pOnLeft ),
            m_pOnRight_( pOnRight ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    pOnLeftPOnRight::pOnLeftPOnRight(pOnLeftPOnRight&& other_) OMG_NOEXCEPT  :m_pOnLeft_ (std::move(other_.m_pOnLeft_))
    ,
    m_pOnRight_ (std::move(other_.m_pOnRight_))
    {
    } 

    pOnLeftPOnRight& pOnLeftPOnRight::operator=(pOnLeftPOnRight&&  other_) OMG_NOEXCEPT {
        pOnLeftPOnRight tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void pOnLeftPOnRight::swap(pOnLeftPOnRight& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_pOnLeft_, other_.m_pOnLeft_);
        swap(m_pOnRight_, other_.m_pOnRight_);
    }  

    bool pOnLeftPOnRight::operator == (const pOnLeftPOnRight& other_) const {
        if (m_pOnLeft_ != other_.m_pOnLeft_) {
            return false;
        }
        if (m_pOnRight_ != other_.m_pOnRight_) {
            return false;
        }
        return true;
    }
    bool pOnLeftPOnRight::operator != (const pOnLeftPOnRight& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const pOnLeftPOnRight& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "pOnLeft: " << std::setprecision(9) <<sample.pOnLeft()<<", ";
        o << "pOnRight: " << std::setprecision(9) <<sample.pOnRight() ;
        o <<"]";
        return o;
    }

    // ---- levelOnLevelOff: 

    levelOnLevelOff::levelOnLevelOff() :
        m_levelOn_ (0) ,
        m_levelOff_ (0)  {
    }   

    levelOnLevelOff::levelOnLevelOff (
        uint8_t levelOn,
        uint8_t levelOff)
        :
            m_levelOn_( levelOn ),
            m_levelOff_( levelOff ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    levelOnLevelOff::levelOnLevelOff(levelOnLevelOff&& other_) OMG_NOEXCEPT  :m_levelOn_ (std::move(other_.m_levelOn_))
    ,
    m_levelOff_ (std::move(other_.m_levelOff_))
    {
    } 

    levelOnLevelOff& levelOnLevelOff::operator=(levelOnLevelOff&&  other_) OMG_NOEXCEPT {
        levelOnLevelOff tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void levelOnLevelOff::swap(levelOnLevelOff& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_levelOn_, other_.m_levelOn_);
        swap(m_levelOff_, other_.m_levelOff_);
    }  

    bool levelOnLevelOff::operator == (const levelOnLevelOff& other_) const {
        if (m_levelOn_ != other_.m_levelOn_) {
            return false;
        }
        if (m_levelOff_ != other_.m_levelOff_) {
            return false;
        }
        return true;
    }
    bool levelOnLevelOff::operator != (const levelOnLevelOff& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const levelOnLevelOff& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "levelOn: <" << std::hex<<(int)sample.levelOn() <<", ";
        o << "levelOff: <" << std::hex<<(int)sample.levelOff()  ;
        o <<"]";
        return o;
    }

    // ---- roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy: 

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy() :
        m_roiAx_ (0) ,
        m_roiAy_ (0) ,
        m_roiBx_ (0) ,
        m_roiBy_ (0) ,
        m_roiCx_ (0) ,
        m_roiCy_ (0) ,
        m_roiDx_ (0) ,
        m_roiDy_ (0)  {
    }   

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy (
        int32_t roiAx,
        int32_t roiAy,
        int32_t roiBx,
        int32_t roiBy,
        int32_t roiCx,
        int32_t roiCy,
        int32_t roiDx,
        int32_t roiDy)
        :
            m_roiAx_( roiAx ),
            m_roiAy_( roiAy ),
            m_roiBx_( roiBx ),
            m_roiBy_( roiBy ),
            m_roiCx_( roiCx ),
            m_roiCy_( roiCy ),
            m_roiDx_( roiDx ),
            m_roiDy_( roiDy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&& other_) OMG_NOEXCEPT  :m_roiAx_ (std::move(other_.m_roiAx_))
    ,
    m_roiAy_ (std::move(other_.m_roiAy_))
    ,
    m_roiBx_ (std::move(other_.m_roiBx_))
    ,
    m_roiBy_ (std::move(other_.m_roiBy_))
    ,
    m_roiCx_ (std::move(other_.m_roiCx_))
    ,
    m_roiCy_ (std::move(other_.m_roiCy_))
    ,
    m_roiDx_ (std::move(other_.m_roiDx_))
    ,
    m_roiDy_ (std::move(other_.m_roiDy_))
    {
    } 

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&  other_) OMG_NOEXCEPT {
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiAx_, other_.m_roiAx_);
        swap(m_roiAy_, other_.m_roiAy_);
        swap(m_roiBx_, other_.m_roiBx_);
        swap(m_roiBy_, other_.m_roiBy_);
        swap(m_roiCx_, other_.m_roiCx_);
        swap(m_roiCy_, other_.m_roiCy_);
        swap(m_roiDx_, other_.m_roiDx_);
        swap(m_roiDy_, other_.m_roiDy_);
    }  

    bool roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator == (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const {
        if (m_roiAx_ != other_.m_roiAx_) {
            return false;
        }
        if (m_roiAy_ != other_.m_roiAy_) {
            return false;
        }
        if (m_roiBx_ != other_.m_roiBx_) {
            return false;
        }
        if (m_roiBy_ != other_.m_roiBy_) {
            return false;
        }
        if (m_roiCx_ != other_.m_roiCx_) {
            return false;
        }
        if (m_roiCy_ != other_.m_roiCy_) {
            return false;
        }
        if (m_roiDx_ != other_.m_roiDx_) {
            return false;
        }
        if (m_roiDy_ != other_.m_roiDy_) {
            return false;
        }
        return true;
    }
    bool roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator != (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiAx: " << sample.roiAx()<<", ";
        o << "roiAy: " << sample.roiAy()<<", ";
        o << "roiBx: " << sample.roiBx()<<", ";
        o << "roiBy: " << sample.roiBy()<<", ";
        o << "roiCx: " << sample.roiCx()<<", ";
        o << "roiCy: " << sample.roiCy()<<", ";
        o << "roiDx: " << sample.roiDx()<<", ";
        o << "roiDy: " << sample.roiDy() ;
        o <<"]";
        return o;
    }

    // ---- leftRight: 

    leftRight::leftRight()  {
    }   

    leftRight::leftRight (
        const ::rti::core::bounded_sequence< bool, 786432 >& left,
        const ::rti::core::bounded_sequence< bool, 786432 >& right)
        :
            m_left_( left ),
            m_right_( right ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    leftRight::leftRight(leftRight&& other_) OMG_NOEXCEPT  :m_left_ (std::move(other_.m_left_))
    ,
    m_right_ (std::move(other_.m_right_))
    {
    } 

    leftRight& leftRight::operator=(leftRight&&  other_) OMG_NOEXCEPT {
        leftRight tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void leftRight::swap(leftRight& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_left_, other_.m_left_);
        swap(m_right_, other_.m_right_);
    }  

    bool leftRight::operator == (const leftRight& other_) const {
        if (m_left_ != other_.m_left_) {
            return false;
        }
        if (m_right_ != other_.m_right_) {
            return false;
        }
        return true;
    }
    bool leftRight::operator != (const leftRight& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const leftRight& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "left: " << sample.left()<<", ";
        o << "right: " << sample.right() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskIprTrace  

namespace DdsJobWzskIprCorner {

    // ---- setNTarget_req: 

    setNTarget_req::setNTarget_req() :
        m_NTarget_ (0)  {
    }   

    setNTarget_req::setNTarget_req (
        uint16_t NTarget)
        :
            m_NTarget_( NTarget ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setNTarget_req::setNTarget_req(setNTarget_req&& other_) OMG_NOEXCEPT  :m_NTarget_ (std::move(other_.m_NTarget_))
    {
    } 

    setNTarget_req& setNTarget_req::operator=(setNTarget_req&&  other_) OMG_NOEXCEPT {
        setNTarget_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setNTarget_req::swap(setNTarget_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_NTarget_, other_.m_NTarget_);
    }  

    bool setNTarget_req::operator == (const setNTarget_req& other_) const {
        if (m_NTarget_ != other_.m_NTarget_) {
            return false;
        }
        return true;
    }
    bool setNTarget_req::operator != (const setNTarget_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setNTarget_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "NTarget: " << sample.NTarget() ;
        o <<"]";
        return o;
    }

    // ---- setNTarget_reply: 

    setNTarget_reply::setNTarget_reply() :
        m_success_ (0)  {
    }   

    setNTarget_reply::setNTarget_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setNTarget_reply::setNTarget_reply(setNTarget_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setNTarget_reply& setNTarget_reply::operator=(setNTarget_reply&&  other_) OMG_NOEXCEPT {
        setNTarget_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setNTarget_reply::swap(setNTarget_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setNTarget_reply::operator == (const setNTarget_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setNTarget_reply::operator != (const setNTarget_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setNTarget_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setRoi_req: 

    setRoi_req::setRoi_req() :
        m_roiAx_ (0) ,
        m_roiAy_ (0) ,
        m_roiBx_ (0) ,
        m_roiBy_ (0) ,
        m_roiCx_ (0) ,
        m_roiCy_ (0) ,
        m_roiDx_ (0) ,
        m_roiDy_ (0)  {
    }   

    setRoi_req::setRoi_req (
        int32_t roiAx,
        int32_t roiAy,
        int32_t roiBx,
        int32_t roiBy,
        int32_t roiCx,
        int32_t roiCy,
        int32_t roiDx,
        int32_t roiDy)
        :
            m_roiAx_( roiAx ),
            m_roiAy_( roiAy ),
            m_roiBx_( roiBx ),
            m_roiBy_( roiBy ),
            m_roiCx_( roiCx ),
            m_roiCy_( roiCy ),
            m_roiDx_( roiDx ),
            m_roiDy_( roiDy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoi_req::setRoi_req(setRoi_req&& other_) OMG_NOEXCEPT  :m_roiAx_ (std::move(other_.m_roiAx_))
    ,
    m_roiAy_ (std::move(other_.m_roiAy_))
    ,
    m_roiBx_ (std::move(other_.m_roiBx_))
    ,
    m_roiBy_ (std::move(other_.m_roiBy_))
    ,
    m_roiCx_ (std::move(other_.m_roiCx_))
    ,
    m_roiCy_ (std::move(other_.m_roiCy_))
    ,
    m_roiDx_ (std::move(other_.m_roiDx_))
    ,
    m_roiDy_ (std::move(other_.m_roiDy_))
    {
    } 

    setRoi_req& setRoi_req::operator=(setRoi_req&&  other_) OMG_NOEXCEPT {
        setRoi_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoi_req::swap(setRoi_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiAx_, other_.m_roiAx_);
        swap(m_roiAy_, other_.m_roiAy_);
        swap(m_roiBx_, other_.m_roiBx_);
        swap(m_roiBy_, other_.m_roiBy_);
        swap(m_roiCx_, other_.m_roiCx_);
        swap(m_roiCy_, other_.m_roiCy_);
        swap(m_roiDx_, other_.m_roiDx_);
        swap(m_roiDy_, other_.m_roiDy_);
    }  

    bool setRoi_req::operator == (const setRoi_req& other_) const {
        if (m_roiAx_ != other_.m_roiAx_) {
            return false;
        }
        if (m_roiAy_ != other_.m_roiAy_) {
            return false;
        }
        if (m_roiBx_ != other_.m_roiBx_) {
            return false;
        }
        if (m_roiBy_ != other_.m_roiBy_) {
            return false;
        }
        if (m_roiCx_ != other_.m_roiCx_) {
            return false;
        }
        if (m_roiCy_ != other_.m_roiCy_) {
            return false;
        }
        if (m_roiDx_ != other_.m_roiDx_) {
            return false;
        }
        if (m_roiDy_ != other_.m_roiDy_) {
            return false;
        }
        return true;
    }
    bool setRoi_req::operator != (const setRoi_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoi_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiAx: " << sample.roiAx()<<", ";
        o << "roiAy: " << sample.roiAy()<<", ";
        o << "roiBx: " << sample.roiBx()<<", ";
        o << "roiBy: " << sample.roiBy()<<", ";
        o << "roiCx: " << sample.roiCx()<<", ";
        o << "roiCy: " << sample.roiCy()<<", ";
        o << "roiDx: " << sample.roiDx()<<", ";
        o << "roiDy: " << sample.roiDy() ;
        o <<"]";
        return o;
    }

    // ---- setRoi_reply: 

    setRoi_reply::setRoi_reply() :
        m_success_ (0)  {
    }   

    setRoi_reply::setRoi_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoi_reply::setRoi_reply(setRoi_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setRoi_reply& setRoi_reply::operator=(setRoi_reply&&  other_) OMG_NOEXCEPT {
        setRoi_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoi_reply::swap(setRoi_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setRoi_reply::operator == (const setRoi_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setRoi_reply::operator != (const setRoi_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoi_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setRoiNotFull_req: 

    setRoiNotFull_req::setRoiNotFull_req() :
        m_roiNotFull_ (0)  {
    }   

    setRoiNotFull_req::setRoiNotFull_req (
        bool roiNotFull)
        :
            m_roiNotFull_( roiNotFull ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoiNotFull_req::setRoiNotFull_req(setRoiNotFull_req&& other_) OMG_NOEXCEPT  :m_roiNotFull_ (std::move(other_.m_roiNotFull_))
    {
    } 

    setRoiNotFull_req& setRoiNotFull_req::operator=(setRoiNotFull_req&&  other_) OMG_NOEXCEPT {
        setRoiNotFull_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoiNotFull_req::swap(setRoiNotFull_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiNotFull_, other_.m_roiNotFull_);
    }  

    bool setRoiNotFull_req::operator == (const setRoiNotFull_req& other_) const {
        if (m_roiNotFull_ != other_.m_roiNotFull_) {
            return false;
        }
        return true;
    }
    bool setRoiNotFull_req::operator != (const setRoiNotFull_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoiNotFull_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiNotFull: " << sample.roiNotFull() ;
        o <<"]";
        return o;
    }

    // ---- setRoiNotFull_reply: 

    setRoiNotFull_reply::setRoiNotFull_reply() :
        m_success_ (0)  {
    }   

    setRoiNotFull_reply::setRoiNotFull_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRoiNotFull_reply::setRoiNotFull_reply(setRoiNotFull_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setRoiNotFull_reply& setRoiNotFull_reply::operator=(setRoiNotFull_reply&&  other_) OMG_NOEXCEPT {
        setRoiNotFull_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRoiNotFull_reply::swap(setRoiNotFull_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setRoiNotFull_reply::operator == (const setRoiNotFull_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setRoiNotFull_reply::operator != (const setRoiNotFull_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRoiNotFull_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- NTarget: 

    NTarget::NTarget() :
        m__NTarget_ (0)  {
    }   

    NTarget::NTarget (
        uint16_t _NTarget)
        :
            m__NTarget_( _NTarget ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    NTarget::NTarget(NTarget&& other_) OMG_NOEXCEPT  :m__NTarget_ (std::move(other_.m__NTarget_))
    {
    } 

    NTarget& NTarget::operator=(NTarget&&  other_) OMG_NOEXCEPT {
        NTarget tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void NTarget::swap(NTarget& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m__NTarget_, other_.m__NTarget_);
    }  

    bool NTarget::operator == (const NTarget& other_) const {
        if (m__NTarget_ != other_.m__NTarget_) {
            return false;
        }
        return true;
    }
    bool NTarget::operator != (const NTarget& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const NTarget& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "_NTarget: " << sample._NTarget() ;
        o <<"]";
        return o;
    }

    // ---- roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy: 

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy() :
        m_roiAx_ (0) ,
        m_roiAy_ (0) ,
        m_roiBx_ (0) ,
        m_roiBy_ (0) ,
        m_roiCx_ (0) ,
        m_roiCy_ (0) ,
        m_roiDx_ (0) ,
        m_roiDy_ (0)  {
    }   

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy (
        int32_t roiAx,
        int32_t roiAy,
        int32_t roiBx,
        int32_t roiBy,
        int32_t roiCx,
        int32_t roiCy,
        int32_t roiDx,
        int32_t roiDy)
        :
            m_roiAx_( roiAx ),
            m_roiAy_( roiAy ),
            m_roiBx_( roiBx ),
            m_roiBy_( roiBy ),
            m_roiCx_( roiCx ),
            m_roiCy_( roiCy ),
            m_roiDx_( roiDx ),
            m_roiDy_( roiDy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&& other_) OMG_NOEXCEPT  :m_roiAx_ (std::move(other_.m_roiAx_))
    ,
    m_roiAy_ (std::move(other_.m_roiAy_))
    ,
    m_roiBx_ (std::move(other_.m_roiBx_))
    ,
    m_roiBy_ (std::move(other_.m_roiBy_))
    ,
    m_roiCx_ (std::move(other_.m_roiCx_))
    ,
    m_roiCy_ (std::move(other_.m_roiCy_))
    ,
    m_roiDx_ (std::move(other_.m_roiDx_))
    ,
    m_roiDy_ (std::move(other_.m_roiDy_))
    {
    } 

    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator=(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy&&  other_) OMG_NOEXCEPT {
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::swap(roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_roiAx_, other_.m_roiAx_);
        swap(m_roiAy_, other_.m_roiAy_);
        swap(m_roiBx_, other_.m_roiBx_);
        swap(m_roiBy_, other_.m_roiBy_);
        swap(m_roiCx_, other_.m_roiCx_);
        swap(m_roiCy_, other_.m_roiCy_);
        swap(m_roiDx_, other_.m_roiDx_);
        swap(m_roiDy_, other_.m_roiDy_);
    }  

    bool roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator == (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const {
        if (m_roiAx_ != other_.m_roiAx_) {
            return false;
        }
        if (m_roiAy_ != other_.m_roiAy_) {
            return false;
        }
        if (m_roiBx_ != other_.m_roiBx_) {
            return false;
        }
        if (m_roiBy_ != other_.m_roiBy_) {
            return false;
        }
        if (m_roiCx_ != other_.m_roiCx_) {
            return false;
        }
        if (m_roiCy_ != other_.m_roiCy_) {
            return false;
        }
        if (m_roiDx_ != other_.m_roiDx_) {
            return false;
        }
        if (m_roiDy_ != other_.m_roiDy_) {
            return false;
        }
        return true;
    }
    bool roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy::operator != (const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "roiAx: " << sample.roiAx()<<", ";
        o << "roiAy: " << sample.roiAy()<<", ";
        o << "roiBx: " << sample.roiBx()<<", ";
        o << "roiBy: " << sample.roiBy()<<", ";
        o << "roiCx: " << sample.roiCx()<<", ";
        o << "roiCy: " << sample.roiCy()<<", ";
        o << "roiDx: " << sample.roiDx()<<", ";
        o << "roiDy: " << sample.roiDy() ;
        o <<"]";
        return o;
    }

    // ---- flgShiftScoreMinScoreMax: 

    flgShiftScoreMinScoreMax::flgShiftScoreMinScoreMax() :
        m_shift_ (0) ,
        m_scoreMin_ (0) ,
        m_scoreMax_ (0)  {
    }   

    flgShiftScoreMinScoreMax::flgShiftScoreMinScoreMax (
        const ::rti::core::bounded_sequence< bool, 786432 >& flg,
        uint8_t shift,
        uint8_t scoreMin,
        uint8_t scoreMax)
        :
            m_flg_( flg ),
            m_shift_( shift ),
            m_scoreMin_( scoreMin ),
            m_scoreMax_( scoreMax ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    flgShiftScoreMinScoreMax::flgShiftScoreMinScoreMax(flgShiftScoreMinScoreMax&& other_) OMG_NOEXCEPT  :m_flg_ (std::move(other_.m_flg_))
    ,
    m_shift_ (std::move(other_.m_shift_))
    ,
    m_scoreMin_ (std::move(other_.m_scoreMin_))
    ,
    m_scoreMax_ (std::move(other_.m_scoreMax_))
    {
    } 

    flgShiftScoreMinScoreMax& flgShiftScoreMinScoreMax::operator=(flgShiftScoreMinScoreMax&&  other_) OMG_NOEXCEPT {
        flgShiftScoreMinScoreMax tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void flgShiftScoreMinScoreMax::swap(flgShiftScoreMinScoreMax& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_flg_, other_.m_flg_);
        swap(m_shift_, other_.m_shift_);
        swap(m_scoreMin_, other_.m_scoreMin_);
        swap(m_scoreMax_, other_.m_scoreMax_);
    }  

    bool flgShiftScoreMinScoreMax::operator == (const flgShiftScoreMinScoreMax& other_) const {
        if (m_flg_ != other_.m_flg_) {
            return false;
        }
        if (m_shift_ != other_.m_shift_) {
            return false;
        }
        if (m_scoreMin_ != other_.m_scoreMin_) {
            return false;
        }
        if (m_scoreMax_ != other_.m_scoreMax_) {
            return false;
        }
        return true;
    }
    bool flgShiftScoreMinScoreMax::operator != (const flgShiftScoreMinScoreMax& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const flgShiftScoreMinScoreMax& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "flg: " << sample.flg()<<", ";
        o << "shift: <" << std::hex<<(int)sample.shift() <<", ";
        o << "scoreMin: <" << std::hex<<(int)sample.scoreMin() <<", ";
        o << "scoreMax: <" << std::hex<<(int)sample.scoreMax()  ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskIprCorner  

namespace DdsJobWzskActServo {

    // ---- moveto_req: 

    moveto_req::moveto_req() :
        m_target_ (0.0f)  {
    }   

    moveto_req::moveto_req (
        float target)
        :
            m_target_( target ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    moveto_req::moveto_req(moveto_req&& other_) OMG_NOEXCEPT  :m_target_ (std::move(other_.m_target_))
    {
    } 

    moveto_req& moveto_req::operator=(moveto_req&&  other_) OMG_NOEXCEPT {
        moveto_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void moveto_req::swap(moveto_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_target_, other_.m_target_);
    }  

    bool moveto_req::operator == (const moveto_req& other_) const {
        if (m_target_ != other_.m_target_) {
            return false;
        }
        return true;
    }
    bool moveto_req::operator != (const moveto_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const moveto_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "target: " << std::setprecision(9) <<sample.target() ;
        o <<"]";
        return o;
    }

    // ---- moveto_reply: 

    moveto_reply::moveto_reply() :
        m_success_ (0)  {
    }   

    moveto_reply::moveto_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    moveto_reply::moveto_reply(moveto_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    moveto_reply& moveto_reply::operator=(moveto_reply&&  other_) OMG_NOEXCEPT {
        moveto_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void moveto_reply::swap(moveto_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool moveto_reply::operator == (const moveto_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool moveto_reply::operator != (const moveto_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const moveto_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- stop_req: 

    stop_req::stop_req() :
        m_dummy_ (0)  {
    }   

    stop_req::stop_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_req::stop_req(stop_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    stop_req& stop_req::operator=(stop_req&&  other_) OMG_NOEXCEPT {
        stop_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_req::swap(stop_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool stop_req::operator == (const stop_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool stop_req::operator != (const stop_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const stop_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- stop_reply: 

    stop_reply::stop_reply() :
        m_success_ (0)  {
    }   

    stop_reply::stop_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    stop_reply::stop_reply(stop_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    stop_reply& stop_reply::operator=(stop_reply&&  other_) OMG_NOEXCEPT {
        stop_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void stop_reply::swap(stop_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool stop_reply::operator == (const stop_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool stop_reply::operator != (const stop_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const stop_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- turn_req: 

    turn_req::turn_req() :
        m_ccwNotCw_ (0)  {
    }   

    turn_req::turn_req (
        bool ccwNotCw)
        :
            m_ccwNotCw_( ccwNotCw ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    turn_req::turn_req(turn_req&& other_) OMG_NOEXCEPT  :m_ccwNotCw_ (std::move(other_.m_ccwNotCw_))
    {
    } 

    turn_req& turn_req::operator=(turn_req&&  other_) OMG_NOEXCEPT {
        turn_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void turn_req::swap(turn_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_ccwNotCw_, other_.m_ccwNotCw_);
    }  

    bool turn_req::operator == (const turn_req& other_) const {
        if (m_ccwNotCw_ != other_.m_ccwNotCw_) {
            return false;
        }
        return true;
    }
    bool turn_req::operator != (const turn_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const turn_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "ccwNotCw: " << sample.ccwNotCw() ;
        o <<"]";
        return o;
    }

    // ---- turn_reply: 

    turn_reply::turn_reply() :
        m_success_ (0)  {
    }   

    turn_reply::turn_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    turn_reply::turn_reply(turn_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    turn_reply& turn_reply::operator=(turn_reply&&  other_) OMG_NOEXCEPT {
        turn_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void turn_reply::swap(turn_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool turn_reply::operator == (const turn_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool turn_reply::operator != (const turn_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const turn_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- zero_req: 

    zero_req::zero_req() :
        m_dummy_ (0)  {
    }   

    zero_req::zero_req (
        bool dummy)
        :
            m_dummy_( dummy ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    zero_req::zero_req(zero_req&& other_) OMG_NOEXCEPT  :m_dummy_ (std::move(other_.m_dummy_))
    {
    } 

    zero_req& zero_req::operator=(zero_req&&  other_) OMG_NOEXCEPT {
        zero_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void zero_req::swap(zero_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_dummy_, other_.m_dummy_);
    }  

    bool zero_req::operator == (const zero_req& other_) const {
        if (m_dummy_ != other_.m_dummy_) {
            return false;
        }
        return true;
    }
    bool zero_req::operator != (const zero_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const zero_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "dummy: " << sample.dummy() ;
        o <<"]";
        return o;
    }

    // ---- zero_reply: 

    zero_reply::zero_reply() :
        m_success_ (0)  {
    }   

    zero_reply::zero_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    zero_reply::zero_reply(zero_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    zero_reply& zero_reply::operator=(zero_reply&&  other_) OMG_NOEXCEPT {
        zero_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void zero_reply::swap(zero_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool zero_reply::operator == (const zero_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool zero_reply::operator != (const zero_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const zero_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- angleTarget: 

    angleTarget::angleTarget() :
        m_angle_ (0.0f) ,
        m_target_ (0.0f)  {
    }   

    angleTarget::angleTarget (
        float angle,
        float target)
        :
            m_angle_( angle ),
            m_target_( target ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    angleTarget::angleTarget(angleTarget&& other_) OMG_NOEXCEPT  :m_angle_ (std::move(other_.m_angle_))
    ,
    m_target_ (std::move(other_.m_target_))
    {
    } 

    angleTarget& angleTarget::operator=(angleTarget&&  other_) OMG_NOEXCEPT {
        angleTarget tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void angleTarget::swap(angleTarget& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_angle_, other_.m_angle_);
        swap(m_target_, other_.m_target_);
    }  

    bool angleTarget::operator == (const angleTarget& other_) const {
        if (m_angle_ != other_.m_angle_) {
            return false;
        }
        if (m_target_ != other_.m_target_) {
            return false;
        }
        return true;
    }
    bool angleTarget::operator != (const angleTarget& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const angleTarget& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "angle: " << std::setprecision(9) <<sample.angle()<<", ";
        o << "target: " << std::setprecision(9) <<sample.target() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskActServo  

namespace DdsJobWzskActLaser {

    // ---- setLeft_req: 

    setLeft_req::setLeft_req() :
        m_left_ (0.0f)  {
    }   

    setLeft_req::setLeft_req (
        float left)
        :
            m_left_( left ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setLeft_req::setLeft_req(setLeft_req&& other_) OMG_NOEXCEPT  :m_left_ (std::move(other_.m_left_))
    {
    } 

    setLeft_req& setLeft_req::operator=(setLeft_req&&  other_) OMG_NOEXCEPT {
        setLeft_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setLeft_req::swap(setLeft_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_left_, other_.m_left_);
    }  

    bool setLeft_req::operator == (const setLeft_req& other_) const {
        if (m_left_ != other_.m_left_) {
            return false;
        }
        return true;
    }
    bool setLeft_req::operator != (const setLeft_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setLeft_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "left: " << std::setprecision(9) <<sample.left() ;
        o <<"]";
        return o;
    }

    // ---- setLeft_reply: 

    setLeft_reply::setLeft_reply() :
        m_success_ (0)  {
    }   

    setLeft_reply::setLeft_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setLeft_reply::setLeft_reply(setLeft_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setLeft_reply& setLeft_reply::operator=(setLeft_reply&&  other_) OMG_NOEXCEPT {
        setLeft_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setLeft_reply::swap(setLeft_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setLeft_reply::operator == (const setLeft_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setLeft_reply::operator != (const setLeft_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setLeft_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setRight_req: 

    setRight_req::setRight_req() :
        m_right_ (0.0f)  {
    }   

    setRight_req::setRight_req (
        float right)
        :
            m_right_( right ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRight_req::setRight_req(setRight_req&& other_) OMG_NOEXCEPT  :m_right_ (std::move(other_.m_right_))
    {
    } 

    setRight_req& setRight_req::operator=(setRight_req&&  other_) OMG_NOEXCEPT {
        setRight_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRight_req::swap(setRight_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_right_, other_.m_right_);
    }  

    bool setRight_req::operator == (const setRight_req& other_) const {
        if (m_right_ != other_.m_right_) {
            return false;
        }
        return true;
    }
    bool setRight_req::operator != (const setRight_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRight_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "right: " << std::setprecision(9) <<sample.right() ;
        o <<"]";
        return o;
    }

    // ---- setRight_reply: 

    setRight_reply::setRight_reply() :
        m_success_ (0)  {
    }   

    setRight_reply::setRight_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setRight_reply::setRight_reply(setRight_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setRight_reply& setRight_reply::operator=(setRight_reply&&  other_) OMG_NOEXCEPT {
        setRight_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setRight_reply::swap(setRight_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setRight_reply::operator == (const setRight_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setRight_reply::operator != (const setRight_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setRight_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- leftRight: 

    leftRight::leftRight() :
        m_left_ (0.0f) ,
        m_right_ (0.0f)  {
    }   

    leftRight::leftRight (
        float left,
        float right)
        :
            m_left_( left ),
            m_right_( right ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    leftRight::leftRight(leftRight&& other_) OMG_NOEXCEPT  :m_left_ (std::move(other_.m_left_))
    ,
    m_right_ (std::move(other_.m_right_))
    {
    } 

    leftRight& leftRight::operator=(leftRight&&  other_) OMG_NOEXCEPT {
        leftRight tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void leftRight::swap(leftRight& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_left_, other_.m_left_);
        swap(m_right_, other_.m_right_);
    }  

    bool leftRight::operator == (const leftRight& other_) const {
        if (m_left_ != other_.m_left_) {
            return false;
        }
        if (m_right_ != other_.m_right_) {
            return false;
        }
        return true;
    }
    bool leftRight::operator != (const leftRight& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const leftRight& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "left: " << std::setprecision(9) <<sample.left()<<", ";
        o << "right: " << std::setprecision(9) <<sample.right() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskActLaser  

namespace DdsJobWzskActExposure {

    // ---- setExposure_req: 

    setExposure_req::setExposure_req() :
        m_autoNotManual_ (0) ,
        m_Texp_ (0.0f)  {
    }   

    setExposure_req::setExposure_req (
        bool autoNotManual,
        float Texp)
        :
            m_autoNotManual_( autoNotManual ),
            m_Texp_( Texp ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setExposure_req::setExposure_req(setExposure_req&& other_) OMG_NOEXCEPT  :m_autoNotManual_ (std::move(other_.m_autoNotManual_))
    ,
    m_Texp_ (std::move(other_.m_Texp_))
    {
    } 

    setExposure_req& setExposure_req::operator=(setExposure_req&&  other_) OMG_NOEXCEPT {
        setExposure_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setExposure_req::swap(setExposure_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_autoNotManual_, other_.m_autoNotManual_);
        swap(m_Texp_, other_.m_Texp_);
    }  

    bool setExposure_req::operator == (const setExposure_req& other_) const {
        if (m_autoNotManual_ != other_.m_autoNotManual_) {
            return false;
        }
        if (m_Texp_ != other_.m_Texp_) {
            return false;
        }
        return true;
    }
    bool setExposure_req::operator != (const setExposure_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setExposure_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "autoNotManual: " << sample.autoNotManual()<<", ";
        o << "Texp: " << std::setprecision(9) <<sample.Texp() ;
        o <<"]";
        return o;
    }

    // ---- setExposure_reply: 

    setExposure_reply::setExposure_reply() :
        m_success_ (0)  {
    }   

    setExposure_reply::setExposure_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setExposure_reply::setExposure_reply(setExposure_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setExposure_reply& setExposure_reply::operator=(setExposure_reply&&  other_) OMG_NOEXCEPT {
        setExposure_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setExposure_reply::swap(setExposure_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setExposure_reply::operator == (const setExposure_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setExposure_reply::operator != (const setExposure_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setExposure_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- setFocus_req: 

    setFocus_req::setFocus_req() :
        m_focus_ (0.0f)  {
    }   

    setFocus_req::setFocus_req (
        float focus)
        :
            m_focus_( focus ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_req::setFocus_req(setFocus_req&& other_) OMG_NOEXCEPT  :m_focus_ (std::move(other_.m_focus_))
    {
    } 

    setFocus_req& setFocus_req::operator=(setFocus_req&&  other_) OMG_NOEXCEPT {
        setFocus_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_req::swap(setFocus_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_focus_, other_.m_focus_);
    }  

    bool setFocus_req::operator == (const setFocus_req& other_) const {
        if (m_focus_ != other_.m_focus_) {
            return false;
        }
        return true;
    }
    bool setFocus_req::operator != (const setFocus_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setFocus_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "focus: " << std::setprecision(9) <<sample.focus() ;
        o <<"]";
        return o;
    }

    // ---- setFocus_reply: 

    setFocus_reply::setFocus_reply() :
        m_success_ (0)  {
    }   

    setFocus_reply::setFocus_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setFocus_reply::setFocus_reply(setFocus_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setFocus_reply& setFocus_reply::operator=(setFocus_reply&&  other_) OMG_NOEXCEPT {
        setFocus_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setFocus_reply::swap(setFocus_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setFocus_reply::operator == (const setFocus_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setFocus_reply::operator != (const setFocus_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setFocus_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- autoNotManualTexp: 

    autoNotManualTexp::autoNotManualTexp() :
        m_autoNotManual_ (0) ,
        m_Texp_ (0.0f)  {
    }   

    autoNotManualTexp::autoNotManualTexp (
        bool autoNotManual,
        float Texp)
        :
            m_autoNotManual_( autoNotManual ),
            m_Texp_( Texp ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    autoNotManualTexp::autoNotManualTexp(autoNotManualTexp&& other_) OMG_NOEXCEPT  :m_autoNotManual_ (std::move(other_.m_autoNotManual_))
    ,
    m_Texp_ (std::move(other_.m_Texp_))
    {
    } 

    autoNotManualTexp& autoNotManualTexp::operator=(autoNotManualTexp&&  other_) OMG_NOEXCEPT {
        autoNotManualTexp tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void autoNotManualTexp::swap(autoNotManualTexp& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_autoNotManual_, other_.m_autoNotManual_);
        swap(m_Texp_, other_.m_Texp_);
    }  

    bool autoNotManualTexp::operator == (const autoNotManualTexp& other_) const {
        if (m_autoNotManual_ != other_.m_autoNotManual_) {
            return false;
        }
        if (m_Texp_ != other_.m_Texp_) {
            return false;
        }
        return true;
    }
    bool autoNotManualTexp::operator != (const autoNotManualTexp& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const autoNotManualTexp& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "autoNotManual: " << sample.autoNotManual()<<", ";
        o << "Texp: " << std::setprecision(9) <<sample.Texp() ;
        o <<"]";
        return o;
    }

    // ---- focus: 

    focus::focus() :
        m__focus_ (0.0f)  {
    }   

    focus::focus (
        float _focus)
        :
            m__focus_( _focus ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    focus::focus(focus&& other_) OMG_NOEXCEPT  :m__focus_ (std::move(other_.m__focus_))
    {
    } 

    focus& focus::operator=(focus&&  other_) OMG_NOEXCEPT {
        focus tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void focus::swap(focus& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m__focus_, other_.m__focus_);
    }  

    bool focus::operator == (const focus& other_) const {
        if (m__focus_ != other_.m__focus_) {
            return false;
        }
        return true;
    }
    bool focus::operator != (const focus& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const focus& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "_focus: " << std::setprecision(9) <<sample._focus() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskActExposure  

namespace DdsJobWzskAcqPtcloud {

    // ---- setDeltaTheta_req: 

    setDeltaTheta_req::setDeltaTheta_req() :
        m_deltaTheta_ (0.0f)  {
    }   

    setDeltaTheta_req::setDeltaTheta_req (
        float deltaTheta)
        :
            m_deltaTheta_( deltaTheta ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setDeltaTheta_req::setDeltaTheta_req(setDeltaTheta_req&& other_) OMG_NOEXCEPT  :m_deltaTheta_ (std::move(other_.m_deltaTheta_))
    {
    } 

    setDeltaTheta_req& setDeltaTheta_req::operator=(setDeltaTheta_req&&  other_) OMG_NOEXCEPT {
        setDeltaTheta_req tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setDeltaTheta_req::swap(setDeltaTheta_req& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_deltaTheta_, other_.m_deltaTheta_);
    }  

    bool setDeltaTheta_req::operator == (const setDeltaTheta_req& other_) const {
        if (m_deltaTheta_ != other_.m_deltaTheta_) {
            return false;
        }
        return true;
    }
    bool setDeltaTheta_req::operator != (const setDeltaTheta_req& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setDeltaTheta_req& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "deltaTheta: " << std::setprecision(9) <<sample.deltaTheta() ;
        o <<"]";
        return o;
    }

    // ---- setDeltaTheta_reply: 

    setDeltaTheta_reply::setDeltaTheta_reply() :
        m_success_ (0)  {
    }   

    setDeltaTheta_reply::setDeltaTheta_reply (
        bool success)
        :
            m_success_( success ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    setDeltaTheta_reply::setDeltaTheta_reply(setDeltaTheta_reply&& other_) OMG_NOEXCEPT  :m_success_ (std::move(other_.m_success_))
    {
    } 

    setDeltaTheta_reply& setDeltaTheta_reply::operator=(setDeltaTheta_reply&&  other_) OMG_NOEXCEPT {
        setDeltaTheta_reply tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void setDeltaTheta_reply::swap(setDeltaTheta_reply& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_success_, other_.m_success_);
    }  

    bool setDeltaTheta_reply::operator == (const setDeltaTheta_reply& other_) const {
        if (m_success_ != other_.m_success_) {
            return false;
        }
        return true;
    }
    bool setDeltaTheta_reply::operator != (const setDeltaTheta_reply& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const setDeltaTheta_reply& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "success: " << sample.success() ;
        o <<"]";
        return o;
    }

    // ---- deltaTheta: 

    deltaTheta::deltaTheta() :
        m__deltaTheta_ (0.0f)  {
    }   

    deltaTheta::deltaTheta (
        float _deltaTheta)
        :
            m__deltaTheta_( _deltaTheta ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    deltaTheta::deltaTheta(deltaTheta&& other_) OMG_NOEXCEPT  :m__deltaTheta_ (std::move(other_.m__deltaTheta_))
    {
    } 

    deltaTheta& deltaTheta::operator=(deltaTheta&&  other_) OMG_NOEXCEPT {
        deltaTheta tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void deltaTheta::swap(deltaTheta& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m__deltaTheta_, other_.m__deltaTheta_);
    }  

    bool deltaTheta::operator == (const deltaTheta& other_) const {
        if (m__deltaTheta_ != other_.m__deltaTheta_) {
            return false;
        }
        return true;
    }
    bool deltaTheta::operator != (const deltaTheta& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const deltaTheta& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "_deltaTheta: " << std::setprecision(9) <<sample._deltaTheta() ;
        o <<"]";
        return o;
    }

    // ---- xYZ: 

    xYZ::xYZ()  {
    }   

    xYZ::xYZ (
        const ::rti::core::bounded_sequence< float, 72000 >& x,
        const ::rti::core::bounded_sequence< float, 72000 >& y,
        const ::rti::core::bounded_sequence< float, 72000 >& z)
        :
            m_x_( x ),
            m_y_( y ),
            m_z_( z ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    xYZ::xYZ(xYZ&& other_) OMG_NOEXCEPT  :m_x_ (std::move(other_.m_x_))
    ,
    m_y_ (std::move(other_.m_y_))
    ,
    m_z_ (std::move(other_.m_z_))
    {
    } 

    xYZ& xYZ::operator=(xYZ&&  other_) OMG_NOEXCEPT {
        xYZ tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void xYZ::swap(xYZ& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_x_, other_.m_x_);
        swap(m_y_, other_.m_y_);
        swap(m_z_, other_.m_z_);
    }  

    bool xYZ::operator == (const xYZ& other_) const {
        if (m_x_ != other_.m_x_) {
            return false;
        }
        if (m_y_ != other_.m_y_) {
            return false;
        }
        if (m_z_ != other_.m_z_) {
            return false;
        }
        return true;
    }
    bool xYZ::operator != (const xYZ& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const xYZ& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "x: " << sample.x()<<", ";
        o << "y: " << sample.y()<<", ";
        o << "z: " << sample.z() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskAcqPtcloud  

namespace DdsJobWzskAcqPreview {

    // ---- gray: 

    gray::gray()  {
    }   

    gray::gray (
        const ::rti::core::bounded_sequence< uint8_t, 49152 >& _gray)
        :
            m__gray_( _gray ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    gray::gray(gray&& other_) OMG_NOEXCEPT  :m__gray_ (std::move(other_.m__gray_))
    {
    } 

    gray& gray::operator=(gray&&  other_) OMG_NOEXCEPT {
        gray tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void gray::swap(gray& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m__gray_, other_.m__gray_);
    }  

    bool gray::operator == (const gray& other_) const {
        if (m__gray_ != other_.m__gray_) {
            return false;
        }
        return true;
    }
    bool gray::operator != (const gray& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const gray& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "_gray: " << sample._gray() ;
        o <<"]";
        return o;
    }

    // ---- redGreenBlue: 

    redGreenBlue::redGreenBlue()  {
    }   

    redGreenBlue::redGreenBlue (
        const ::rti::core::bounded_sequence< uint8_t, 19200 >& red,
        const ::rti::core::bounded_sequence< uint8_t, 19200 >& green,
        const ::rti::core::bounded_sequence< uint8_t, 19200 >& blue)
        :
            m_red_( red ),
            m_green_( green ),
            m_blue_( blue ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    redGreenBlue::redGreenBlue(redGreenBlue&& other_) OMG_NOEXCEPT  :m_red_ (std::move(other_.m_red_))
    ,
    m_green_ (std::move(other_.m_green_))
    ,
    m_blue_ (std::move(other_.m_blue_))
    {
    } 

    redGreenBlue& redGreenBlue::operator=(redGreenBlue&&  other_) OMG_NOEXCEPT {
        redGreenBlue tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void redGreenBlue::swap(redGreenBlue& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_red_, other_.m_red_);
        swap(m_green_, other_.m_green_);
        swap(m_blue_, other_.m_blue_);
    }  

    bool redGreenBlue::operator == (const redGreenBlue& other_) const {
        if (m_red_ != other_.m_red_) {
            return false;
        }
        if (m_green_ != other_.m_green_) {
            return false;
        }
        if (m_blue_ != other_.m_blue_) {
            return false;
        }
        return true;
    }
    bool redGreenBlue::operator != (const redGreenBlue& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const redGreenBlue& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "red: " << sample.red()<<", ";
        o << "green: " << sample.green()<<", ";
        o << "blue: " << sample.blue() ;
        o <<"]";
        return o;
    }

} // namespace DdsJobWzskAcqPreview  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< tinyint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode tinyint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"tinyint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  tinyint */

                if (is_initialized) {
                    return &tinyint_g_tc;
                }

                tinyint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                tinyint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_char;

                /* Initialize the values for member annotations. */
                tinyint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_CHAR;
                tinyint_g_tc._data._annotations._defaultValue._u.char_value = 0;

                tinyint_g_tc._data._sampleAccessInfo = sample_access_info();
                tinyint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &tinyint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo tinyint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo tinyint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &tinyint_g_sampleAccessInfo;
                }

                tinyint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                tinyint_g_sampleAccessInfo.memberAccessInfos = 
                tinyint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(tinyint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        tinyint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        tinyint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                tinyint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                tinyint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< tinyint >;

                tinyint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &tinyint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin tinyint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &tinyint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< tinyint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< tinyint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< utinyint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode utinyint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"utinyint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  utinyint */

                if (is_initialized) {
                    return &utinyint_g_tc;
                }

                utinyint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                utinyint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                utinyint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                utinyint_g_tc._data._annotations._defaultValue._u.octet_value = 0;
                utinyint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                utinyint_g_tc._data._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                utinyint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                utinyint_g_tc._data._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                utinyint_g_tc._data._sampleAccessInfo = sample_access_info();
                utinyint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &utinyint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo utinyint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo utinyint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &utinyint_g_sampleAccessInfo;
                }

                utinyint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                utinyint_g_sampleAccessInfo.memberAccessInfos = 
                utinyint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(utinyint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        utinyint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        utinyint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                utinyint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                utinyint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< utinyint >;

                utinyint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &utinyint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin utinyint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &utinyint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< utinyint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< utinyint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< smallint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode smallint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"smallint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  smallint */

                if (is_initialized) {
                    return &smallint_g_tc;
                }

                smallint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                smallint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                smallint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                smallint_g_tc._data._annotations._defaultValue._u.short_value = 0;
                smallint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                smallint_g_tc._data._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                smallint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                smallint_g_tc._data._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                smallint_g_tc._data._sampleAccessInfo = sample_access_info();
                smallint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &smallint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo smallint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo smallint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &smallint_g_sampleAccessInfo;
                }

                smallint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                smallint_g_sampleAccessInfo.memberAccessInfos = 
                smallint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(smallint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        smallint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        smallint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                smallint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                smallint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< smallint >;

                smallint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &smallint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin smallint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &smallint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< smallint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< smallint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< usmallint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode usmallint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"usmallint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  usmallint */

                if (is_initialized) {
                    return &usmallint_g_tc;
                }

                usmallint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                usmallint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */
                usmallint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                usmallint_g_tc._data._annotations._defaultValue._u.ushort_value = 0;
                usmallint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                usmallint_g_tc._data._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                usmallint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                usmallint_g_tc._data._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                usmallint_g_tc._data._sampleAccessInfo = sample_access_info();
                usmallint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &usmallint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo usmallint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo usmallint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &usmallint_g_sampleAccessInfo;
                }

                usmallint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                usmallint_g_sampleAccessInfo.memberAccessInfos = 
                usmallint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(usmallint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        usmallint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        usmallint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                usmallint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                usmallint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< usmallint >;

                usmallint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &usmallint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin usmallint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &usmallint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< usmallint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< usmallint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< _cxx_int_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode _cxx_int_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"int", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  _cxx_int */

                if (is_initialized) {
                    return &_cxx_int_g_tc;
                }

                _cxx_int_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                _cxx_int_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                _cxx_int_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                _cxx_int_g_tc._data._annotations._defaultValue._u.long_value = 0;
                _cxx_int_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_LONG;
                _cxx_int_g_tc._data._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                _cxx_int_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                _cxx_int_g_tc._data._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                _cxx_int_g_tc._data._sampleAccessInfo = sample_access_info();
                _cxx_int_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &_cxx_int_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo _cxx_int_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo _cxx_int_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &_cxx_int_g_sampleAccessInfo;
                }

                _cxx_int_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                _cxx_int_g_sampleAccessInfo.memberAccessInfos = 
                _cxx_int_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(_cxx_int);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        _cxx_int_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        _cxx_int_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                _cxx_int_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                _cxx_int_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< _cxx_int >;

                _cxx_int_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &_cxx_int_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin _cxx_int_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &_cxx_int_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< _cxx_int_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< _cxx_int_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< uint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode uint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"uint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  uint */

                if (is_initialized) {
                    return &uint_g_tc;
                }

                uint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                uint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                uint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                uint_g_tc._data._annotations._defaultValue._u.ulong_value = 0u;
                uint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                uint_g_tc._data._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                uint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                uint_g_tc._data._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                uint_g_tc._data._sampleAccessInfo = sample_access_info();
                uint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &uint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo uint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo uint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &uint_g_sampleAccessInfo;
                }

                uint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                uint_g_sampleAccessInfo.memberAccessInfos = 
                uint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(uint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        uint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        uint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                uint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                uint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< uint >;

                uint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &uint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin uint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &uint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< uint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< uint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< bigint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode bigint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"bigint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  bigint */

                if (is_initialized) {
                    return &bigint_g_tc;
                }

                bigint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                bigint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_longlong;

                /* Initialize the values for member annotations. */
                bigint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                bigint_g_tc._data._annotations._defaultValue._u.long_long_value = 0ll;
                bigint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                bigint_g_tc._data._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                bigint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                bigint_g_tc._data._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

                bigint_g_tc._data._sampleAccessInfo = sample_access_info();
                bigint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &bigint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo bigint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo bigint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &bigint_g_sampleAccessInfo;
                }

                bigint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                bigint_g_sampleAccessInfo.memberAccessInfos = 
                bigint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(bigint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        bigint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        bigint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                bigint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                bigint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< bigint >;

                bigint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &bigint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin bigint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &bigint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< bigint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< bigint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< ubigint_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ubigint_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"ubigint", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  ubigint */

                if (is_initialized) {
                    return &ubigint_g_tc;
                }

                ubigint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ubigint_g_tc._data._typeCode =  (RTICdrTypeCode *)&DDS_g_tc_ulonglong;

                /* Initialize the values for member annotations. */
                ubigint_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ubigint_g_tc._data._annotations._defaultValue._u.ulong_long_value = 0ull;
                ubigint_g_tc._data._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ubigint_g_tc._data._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ubigint_g_tc._data._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ubigint_g_tc._data._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ubigint_g_tc._data._sampleAccessInfo = sample_access_info();
                ubigint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ubigint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ubigint_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ubigint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ubigint_g_sampleAccessInfo;
                }

                ubigint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ubigint_g_sampleAccessInfo.memberAccessInfos = 
                ubigint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ubigint);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        ubigint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        ubigint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ubigint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ubigint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ubigint >;

                ubigint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ubigint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ubigint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ubigint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< ubigint_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ubigint_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsFloatmat > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DdsFloatmat_g_tc_vec_sequence;

                static DDS_TypeCode_Member DdsFloatmat_g_tc_members[3]=
                {

                    {
                        (char *)"vec",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"M",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"N",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DdsFloatmat_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsFloatmat", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        DdsFloatmat_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DdsFloatmat*/

                if (is_initialized) {
                    return &DdsFloatmat_g_tc;
                }

                DdsFloatmat_g_tc_vec_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 100 > >((100));

                DdsFloatmat_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DdsFloatmat_g_tc_vec_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                DdsFloatmat_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& DdsFloatmat_g_tc_vec_sequence;
                DdsFloatmat_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< uint_AliasTag_t>::get().native();
                DdsFloatmat_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< uint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */

                DdsFloatmat_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                DdsFloatmat_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                DdsFloatmat_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                DdsFloatmat_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
                DdsFloatmat_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                DdsFloatmat_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                DdsFloatmat_g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                DdsFloatmat_g_tc._data._sampleAccessInfo = sample_access_info();
                DdsFloatmat_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DdsFloatmat_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsFloatmat *sample;

                static RTIXCdrMemberAccessInfo DdsFloatmat_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DdsFloatmat_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DdsFloatmat_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsFloatmat);
                if (sample == NULL) {
                    return NULL;
                }

                DdsFloatmat_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->vec() - (char *)sample);

                DdsFloatmat_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->M() - (char *)sample);

                DdsFloatmat_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->N() - (char *)sample);

                DdsFloatmat_g_sampleAccessInfo.memberAccessInfos = 
                DdsFloatmat_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsFloatmat);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DdsFloatmat_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DdsFloatmat_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DdsFloatmat_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DdsFloatmat_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsFloatmat >;

                DdsFloatmat_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DdsFloatmat_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DdsFloatmat_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DdsFloatmat_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsFloatmat >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsFloatmat >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsDoublemat > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DdsDoublemat_g_tc_vec_sequence;

                static DDS_TypeCode_Member DdsDoublemat_g_tc_members[3]=
                {

                    {
                        (char *)"vec",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"M",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"N",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DdsDoublemat_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsDoublemat", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        DdsDoublemat_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DdsDoublemat*/

                if (is_initialized) {
                    return &DdsDoublemat_g_tc;
                }

                DdsDoublemat_g_tc_vec_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 100 > >((100));

                DdsDoublemat_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DdsDoublemat_g_tc_vec_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                DdsDoublemat_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& DdsDoublemat_g_tc_vec_sequence;
                DdsDoublemat_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< uint_AliasTag_t>::get().native();
                DdsDoublemat_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< uint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */

                DdsDoublemat_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                DdsDoublemat_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                DdsDoublemat_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                DdsDoublemat_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
                DdsDoublemat_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                DdsDoublemat_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                DdsDoublemat_g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                DdsDoublemat_g_tc._data._sampleAccessInfo = sample_access_info();
                DdsDoublemat_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DdsDoublemat_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsDoublemat *sample;

                static RTIXCdrMemberAccessInfo DdsDoublemat_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DdsDoublemat_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DdsDoublemat_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsDoublemat);
                if (sample == NULL) {
                    return NULL;
                }

                DdsDoublemat_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->vec() - (char *)sample);

                DdsDoublemat_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->M() - (char *)sample);

                DdsDoublemat_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->N() - (char *)sample);

                DdsDoublemat_g_sampleAccessInfo.memberAccessInfos = 
                DdsDoublemat_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsDoublemat);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        DdsDoublemat_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        DdsDoublemat_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DdsDoublemat_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DdsDoublemat_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsDoublemat >;

                DdsDoublemat_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DdsDoublemat_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DdsDoublemat_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DdsDoublemat_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsDoublemat >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsDoublemat >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< stringvec_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode stringvec_g_tc_string;

                static DDS_TypeCode stringvec_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"stringvec", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  stringvec */

                if (is_initialized) {
                    return &stringvec_g_tc;
                }

                stringvec_g_tc_string = initialize_string_typecode((65536));

                stringvec_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                stringvec_g_tc._data._typeCode =  (RTICdrTypeCode *)&stringvec_g_tc_string;

                /* Initialize the values for member annotations. */
                stringvec_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                stringvec_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                stringvec_g_tc._data._sampleAccessInfo = sample_access_info();
                stringvec_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &stringvec_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo stringvec_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo stringvec_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &stringvec_g_sampleAccessInfo;
                }

                stringvec_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                stringvec_g_sampleAccessInfo.memberAccessInfos = 
                stringvec_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(stringvec);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        stringvec_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        stringvec_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                stringvec_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                stringvec_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< stringvec >;

                stringvec_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &stringvec_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin stringvec_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &stringvec_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< stringvec_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< stringvec_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< vecsref_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode vecsref_g_tc_string;

                static DDS_TypeCode vecsref_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"vecsref", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  vecsref */

                if (is_initialized) {
                    return &vecsref_g_tc;
                }

                vecsref_g_tc_string = initialize_string_typecode((50));

                vecsref_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                vecsref_g_tc._data._typeCode =  (RTICdrTypeCode *)&vecsref_g_tc_string;

                /* Initialize the values for member annotations. */
                vecsref_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                vecsref_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                vecsref_g_tc._data._sampleAccessInfo = sample_access_info();
                vecsref_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &vecsref_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo vecsref_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo vecsref_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &vecsref_g_sampleAccessInfo;
                }

                vecsref_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                vecsref_g_sampleAccessInfo.memberAccessInfos = 
                vecsref_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(vecsref);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        vecsref_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        vecsref_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                vecsref_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                vecsref_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< vecsref >;

                vecsref_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &vecsref_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin vecsref_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &vecsref_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::AliasType& dynamic_type< vecsref_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< vecsref_AliasTag_t >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadAll_sequence;
                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore0_sequence;
                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore1_sequence;
                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore2_sequence;
                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore3_sequence;

                static DDS_TypeCode_Member loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[5]=
                {

                    {
                        (char *)"loadAll",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"loadCore0",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"loadCore1",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"loadCore2",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"loadCore3",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for loadAllLoadCore0LoadCore1LoadCore2LoadCore3*/

                if (is_initialized) {
                    return &loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc;
                }

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadAll_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore0_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore1_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore2_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore3_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadAll_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore0_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore1_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore2_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore3_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadAll_sequence;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore0_sequence;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore1_sequence;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore2_sequence;
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc_loadCore3_sequence;

                /* Initialize the values for member annotations. */

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc._data._sampleAccessInfo = sample_access_info();
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample;

                static RTIXCdrMemberAccessInfo loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[5] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3);
                if (sample == NULL) {
                    return NULL;
                }

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->loadAll() - (char *)sample);

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->loadCore0() - (char *)sample);

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->loadCore1() - (char *)sample);

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->loadCore2() - (char *)sample);

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->loadCore3() - (char *)sample);

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.memberAccessInfos = 
                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >;

                loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &loadAllLoadCore0LoadCore1LoadCore2LoadCore3_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskSrcSysinfo::temp > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode temp_g_tc__temp_sequence;

                static DDS_TypeCode_Member temp_g_tc_members[1]=
                {

                    {
                        (char *)"_temp",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode temp_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskSrcSysinfo::temp", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        temp_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for temp*/

                if (is_initialized) {
                    return &temp_g_tc;
                }

                temp_g_tc__temp_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 60 > >((60));

                temp_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                temp_g_tc__temp_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                temp_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& temp_g_tc__temp_sequence;

                /* Initialize the values for member annotations. */

                temp_g_tc._data._sampleAccessInfo = sample_access_info();
                temp_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &temp_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskSrcSysinfo::temp *sample;

                static RTIXCdrMemberAccessInfo temp_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo temp_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &temp_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskSrcSysinfo::temp);
                if (sample == NULL) {
                    return NULL;
                }

                temp_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->_temp() - (char *)sample);

                temp_g_sampleAccessInfo.memberAccessInfos = 
                temp_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskSrcSysinfo::temp);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        temp_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        temp_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                temp_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                temp_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskSrcSysinfo::temp >;

                temp_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &temp_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin temp_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &temp_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskSrcSysinfo::temp >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskSrcSysinfo::temp >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setLevel_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setLevel_req_g_tc_members[2]=
                {

                    {
                        (char *)"levelOn",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"levelOff",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setLevel_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setLevel_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        setLevel_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setLevel_req*/

                if (is_initialized) {
                    return &setLevel_req_g_tc;
                }

                setLevel_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setLevel_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();
                setLevel_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                setLevel_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                setLevel_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                setLevel_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                setLevel_req_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                setLevel_req_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                setLevel_req_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                setLevel_req_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                setLevel_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setLevel_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setLevel_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setLevel_req *sample;

                static RTIXCdrMemberAccessInfo setLevel_req_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setLevel_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setLevel_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setLevel_req);
                if (sample == NULL) {
                    return NULL;
                }

                setLevel_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->levelOn() - (char *)sample);

                setLevel_req_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->levelOff() - (char *)sample);

                setLevel_req_g_sampleAccessInfo.memberAccessInfos = 
                setLevel_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setLevel_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setLevel_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setLevel_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setLevel_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setLevel_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setLevel_req >;

                setLevel_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setLevel_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setLevel_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setLevel_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setLevel_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setLevel_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setLevel_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setLevel_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setLevel_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setLevel_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setLevel_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setLevel_reply*/

                if (is_initialized) {
                    return &setLevel_reply_g_tc;
                }

                setLevel_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setLevel_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setLevel_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setLevel_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setLevel_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setLevel_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setLevel_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setLevel_reply *sample;

                static RTIXCdrMemberAccessInfo setLevel_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setLevel_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setLevel_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setLevel_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setLevel_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setLevel_reply_g_sampleAccessInfo.memberAccessInfos = 
                setLevel_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setLevel_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setLevel_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setLevel_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setLevel_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setLevel_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setLevel_reply >;

                setLevel_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setLevel_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setLevel_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setLevel_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setLevel_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setLevel_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setRoi_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoi_req_g_tc_members[8]=
                {

                    {
                        (char *)"roiAx",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiAy",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBx",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBy",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCx",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCy",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDx",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDy",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoi_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setRoi_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        setRoi_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoi_req*/

                if (is_initialized) {
                    return &setRoi_req_g_tc;
                }

                setRoi_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoi_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                setRoi_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoi_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoi_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setRoi_req *sample;

                static RTIXCdrMemberAccessInfo setRoi_req_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoi_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoi_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setRoi_req);
                if (sample == NULL) {
                    return NULL;
                }

                setRoi_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDy() - (char *)sample);

                setRoi_req_g_sampleAccessInfo.memberAccessInfos = 
                setRoi_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setRoi_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoi_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoi_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoi_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoi_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setRoi_req >;

                setRoi_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoi_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoi_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoi_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setRoi_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setRoi_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setRoi_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoi_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoi_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setRoi_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoi_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoi_reply*/

                if (is_initialized) {
                    return &setRoi_reply_g_tc;
                }

                setRoi_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoi_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoi_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoi_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoi_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoi_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoi_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setRoi_reply *sample;

                static RTIXCdrMemberAccessInfo setRoi_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoi_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoi_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setRoi_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setRoi_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setRoi_reply_g_sampleAccessInfo.memberAccessInfos = 
                setRoi_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setRoi_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoi_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoi_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoi_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoi_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setRoi_reply >;

                setRoi_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoi_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoi_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoi_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setRoi_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setRoi_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setRoiNotFull_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoiNotFull_req_g_tc_members[1]=
                {

                    {
                        (char *)"roiNotFull",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoiNotFull_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setRoiNotFull_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoiNotFull_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoiNotFull_req*/

                if (is_initialized) {
                    return &setRoiNotFull_req_g_tc;
                }

                setRoiNotFull_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoiNotFull_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoiNotFull_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoiNotFull_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoiNotFull_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoiNotFull_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoiNotFull_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setRoiNotFull_req *sample;

                static RTIXCdrMemberAccessInfo setRoiNotFull_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoiNotFull_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setRoiNotFull_req);
                if (sample == NULL) {
                    return NULL;
                }

                setRoiNotFull_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiNotFull() - (char *)sample);

                setRoiNotFull_req_g_sampleAccessInfo.memberAccessInfos = 
                setRoiNotFull_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setRoiNotFull_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoiNotFull_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoiNotFull_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoiNotFull_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoiNotFull_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setRoiNotFull_req >;

                setRoiNotFull_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoiNotFull_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoiNotFull_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setRoiNotFull_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setRoiNotFull_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::setRoiNotFull_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoiNotFull_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoiNotFull_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::setRoiNotFull_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoiNotFull_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoiNotFull_reply*/

                if (is_initialized) {
                    return &setRoiNotFull_reply_g_tc;
                }

                setRoiNotFull_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoiNotFull_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoiNotFull_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoiNotFull_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoiNotFull_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoiNotFull_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoiNotFull_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::setRoiNotFull_reply *sample;

                static RTIXCdrMemberAccessInfo setRoiNotFull_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoiNotFull_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::setRoiNotFull_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setRoiNotFull_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setRoiNotFull_reply_g_sampleAccessInfo.memberAccessInfos = 
                setRoiNotFull_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::setRoiNotFull_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoiNotFull_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoiNotFull_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoiNotFull_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoiNotFull_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::setRoiNotFull_reply >;

                setRoiNotFull_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoiNotFull_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoiNotFull_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::setRoiNotFull_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::setRoiNotFull_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::pOnLeftPOnRight > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member pOnLeftPOnRight_g_tc_members[2]=
                {

                    {
                        (char *)"pOnLeft",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"pOnRight",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode pOnLeftPOnRight_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::pOnLeftPOnRight", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        pOnLeftPOnRight_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for pOnLeftPOnRight*/

                if (is_initialized) {
                    return &pOnLeftPOnRight_g_tc;
                }

                pOnLeftPOnRight_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                pOnLeftPOnRight_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                pOnLeftPOnRight_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                pOnLeftPOnRight_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                pOnLeftPOnRight_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                pOnLeftPOnRight_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                pOnLeftPOnRight_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                pOnLeftPOnRight_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                pOnLeftPOnRight_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                pOnLeftPOnRight_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                pOnLeftPOnRight_g_tc._data._sampleAccessInfo = sample_access_info();
                pOnLeftPOnRight_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &pOnLeftPOnRight_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::pOnLeftPOnRight *sample;

                static RTIXCdrMemberAccessInfo pOnLeftPOnRight_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo pOnLeftPOnRight_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &pOnLeftPOnRight_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::pOnLeftPOnRight);
                if (sample == NULL) {
                    return NULL;
                }

                pOnLeftPOnRight_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->pOnLeft() - (char *)sample);

                pOnLeftPOnRight_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->pOnRight() - (char *)sample);

                pOnLeftPOnRight_g_sampleAccessInfo.memberAccessInfos = 
                pOnLeftPOnRight_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::pOnLeftPOnRight);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        pOnLeftPOnRight_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        pOnLeftPOnRight_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                pOnLeftPOnRight_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                pOnLeftPOnRight_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::pOnLeftPOnRight >;

                pOnLeftPOnRight_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &pOnLeftPOnRight_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin pOnLeftPOnRight_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &pOnLeftPOnRight_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::pOnLeftPOnRight >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::pOnLeftPOnRight >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::levelOnLevelOff > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member levelOnLevelOff_g_tc_members[2]=
                {

                    {
                        (char *)"levelOn",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"levelOff",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode levelOnLevelOff_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::levelOnLevelOff", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        levelOnLevelOff_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for levelOnLevelOff*/

                if (is_initialized) {
                    return &levelOnLevelOff_g_tc;
                }

                levelOnLevelOff_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                levelOnLevelOff_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();
                levelOnLevelOff_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                levelOnLevelOff_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                levelOnLevelOff_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                levelOnLevelOff_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                levelOnLevelOff_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                levelOnLevelOff_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                levelOnLevelOff_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                levelOnLevelOff_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                levelOnLevelOff_g_tc._data._sampleAccessInfo = sample_access_info();
                levelOnLevelOff_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &levelOnLevelOff_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::levelOnLevelOff *sample;

                static RTIXCdrMemberAccessInfo levelOnLevelOff_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo levelOnLevelOff_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &levelOnLevelOff_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::levelOnLevelOff);
                if (sample == NULL) {
                    return NULL;
                }

                levelOnLevelOff_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->levelOn() - (char *)sample);

                levelOnLevelOff_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->levelOff() - (char *)sample);

                levelOnLevelOff_g_sampleAccessInfo.memberAccessInfos = 
                levelOnLevelOff_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::levelOnLevelOff);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        levelOnLevelOff_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        levelOnLevelOff_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                levelOnLevelOff_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                levelOnLevelOff_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::levelOnLevelOff >;

                levelOnLevelOff_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &levelOnLevelOff_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin levelOnLevelOff_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &levelOnLevelOff_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::levelOnLevelOff >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::levelOnLevelOff >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[8]=
                {

                    {
                        (char *)"roiAx",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiAy",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBx",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBy",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCx",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCy",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDx",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDy",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*/

                if (is_initialized) {
                    return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc;
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._sampleAccessInfo = sample_access_info();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample;

                static RTIXCdrMemberAccessInfo roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);
                if (sample == NULL) {
                    return NULL;
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.memberAccessInfos = 
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprTrace::leftRight > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode leftRight_g_tc_left_sequence;
                static DDS_TypeCode leftRight_g_tc_right_sequence;

                static DDS_TypeCode_Member leftRight_g_tc_members[2]=
                {

                    {
                        (char *)"left",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"right",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode leftRight_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprTrace::leftRight", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        leftRight_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for leftRight*/

                if (is_initialized) {
                    return &leftRight_g_tc;
                }

                leftRight_g_tc_left_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< bool, 786432 > >((786432));
                leftRight_g_tc_right_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< bool, 786432 > >((786432));

                leftRight_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                leftRight_g_tc_left_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                leftRight_g_tc_right_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                leftRight_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& leftRight_g_tc_left_sequence;
                leftRight_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& leftRight_g_tc_right_sequence;

                /* Initialize the values for member annotations. */

                leftRight_g_tc._data._sampleAccessInfo = sample_access_info();
                leftRight_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &leftRight_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprTrace::leftRight *sample;

                static RTIXCdrMemberAccessInfo leftRight_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo leftRight_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &leftRight_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprTrace::leftRight);
                if (sample == NULL) {
                    return NULL;
                }

                leftRight_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->left() - (char *)sample);

                leftRight_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->right() - (char *)sample);

                leftRight_g_sampleAccessInfo.memberAccessInfos = 
                leftRight_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprTrace::leftRight);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        leftRight_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        leftRight_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                leftRight_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                leftRight_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprTrace::leftRight >;

                leftRight_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &leftRight_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin leftRight_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &leftRight_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprTrace::leftRight >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprTrace::leftRight >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setNTarget_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setNTarget_req_g_tc_members[1]=
                {

                    {
                        (char *)"NTarget",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setNTarget_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setNTarget_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setNTarget_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setNTarget_req*/

                if (is_initialized) {
                    return &setNTarget_req_g_tc;
                }

                setNTarget_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setNTarget_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< usmallint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                setNTarget_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                setNTarget_req_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                setNTarget_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                setNTarget_req_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                setNTarget_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                setNTarget_req_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                setNTarget_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setNTarget_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setNTarget_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setNTarget_req *sample;

                static RTIXCdrMemberAccessInfo setNTarget_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setNTarget_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setNTarget_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setNTarget_req);
                if (sample == NULL) {
                    return NULL;
                }

                setNTarget_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NTarget() - (char *)sample);

                setNTarget_req_g_sampleAccessInfo.memberAccessInfos = 
                setNTarget_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setNTarget_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setNTarget_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setNTarget_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setNTarget_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setNTarget_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setNTarget_req >;

                setNTarget_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setNTarget_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setNTarget_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setNTarget_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setNTarget_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setNTarget_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setNTarget_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setNTarget_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setNTarget_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setNTarget_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setNTarget_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setNTarget_reply*/

                if (is_initialized) {
                    return &setNTarget_reply_g_tc;
                }

                setNTarget_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setNTarget_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setNTarget_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setNTarget_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setNTarget_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setNTarget_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setNTarget_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setNTarget_reply *sample;

                static RTIXCdrMemberAccessInfo setNTarget_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setNTarget_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setNTarget_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setNTarget_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setNTarget_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setNTarget_reply_g_sampleAccessInfo.memberAccessInfos = 
                setNTarget_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setNTarget_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setNTarget_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setNTarget_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setNTarget_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setNTarget_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setNTarget_reply >;

                setNTarget_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setNTarget_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setNTarget_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setNTarget_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setNTarget_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setNTarget_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setRoi_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoi_req_g_tc_members[8]=
                {

                    {
                        (char *)"roiAx",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiAy",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBx",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBy",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCx",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCy",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDx",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDy",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoi_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setRoi_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        setRoi_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoi_req*/

                if (is_initialized) {
                    return &setRoi_req_g_tc;
                }

                setRoi_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoi_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                setRoi_req_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                setRoi_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._defaultValue._u.long_value = 0;
                setRoi_req_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                setRoi_req_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                setRoi_req_g_tc_members[7]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                setRoi_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoi_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoi_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setRoi_req *sample;

                static RTIXCdrMemberAccessInfo setRoi_req_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoi_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoi_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setRoi_req);
                if (sample == NULL) {
                    return NULL;
                }

                setRoi_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCy() - (char *)sample);

                setRoi_req_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDx() - (char *)sample);

                setRoi_req_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDy() - (char *)sample);

                setRoi_req_g_sampleAccessInfo.memberAccessInfos = 
                setRoi_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setRoi_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoi_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoi_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoi_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoi_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setRoi_req >;

                setRoi_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoi_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoi_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoi_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setRoi_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setRoi_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setRoi_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoi_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoi_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setRoi_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoi_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoi_reply*/

                if (is_initialized) {
                    return &setRoi_reply_g_tc;
                }

                setRoi_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoi_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoi_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoi_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoi_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoi_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoi_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setRoi_reply *sample;

                static RTIXCdrMemberAccessInfo setRoi_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoi_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoi_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setRoi_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setRoi_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setRoi_reply_g_sampleAccessInfo.memberAccessInfos = 
                setRoi_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setRoi_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoi_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoi_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoi_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoi_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setRoi_reply >;

                setRoi_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoi_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoi_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoi_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setRoi_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setRoi_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setRoiNotFull_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoiNotFull_req_g_tc_members[1]=
                {

                    {
                        (char *)"roiNotFull",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoiNotFull_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setRoiNotFull_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoiNotFull_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoiNotFull_req*/

                if (is_initialized) {
                    return &setRoiNotFull_req_g_tc;
                }

                setRoiNotFull_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoiNotFull_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoiNotFull_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoiNotFull_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoiNotFull_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoiNotFull_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoiNotFull_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setRoiNotFull_req *sample;

                static RTIXCdrMemberAccessInfo setRoiNotFull_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoiNotFull_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setRoiNotFull_req);
                if (sample == NULL) {
                    return NULL;
                }

                setRoiNotFull_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiNotFull() - (char *)sample);

                setRoiNotFull_req_g_sampleAccessInfo.memberAccessInfos = 
                setRoiNotFull_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setRoiNotFull_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoiNotFull_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoiNotFull_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoiNotFull_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoiNotFull_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setRoiNotFull_req >;

                setRoiNotFull_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoiNotFull_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoiNotFull_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setRoiNotFull_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setRoiNotFull_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::setRoiNotFull_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRoiNotFull_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRoiNotFull_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::setRoiNotFull_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRoiNotFull_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRoiNotFull_reply*/

                if (is_initialized) {
                    return &setRoiNotFull_reply_g_tc;
                }

                setRoiNotFull_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRoiNotFull_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRoiNotFull_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRoiNotFull_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRoiNotFull_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setRoiNotFull_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRoiNotFull_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::setRoiNotFull_reply *sample;

                static RTIXCdrMemberAccessInfo setRoiNotFull_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRoiNotFull_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::setRoiNotFull_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setRoiNotFull_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setRoiNotFull_reply_g_sampleAccessInfo.memberAccessInfos = 
                setRoiNotFull_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::setRoiNotFull_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRoiNotFull_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRoiNotFull_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRoiNotFull_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRoiNotFull_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::setRoiNotFull_reply >;

                setRoiNotFull_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRoiNotFull_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRoiNotFull_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRoiNotFull_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::setRoiNotFull_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::setRoiNotFull_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::NTarget > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member NTarget_g_tc_members[1]=
                {

                    {
                        (char *)"_NTarget",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode NTarget_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::NTarget", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        NTarget_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for NTarget*/

                if (is_initialized) {
                    return &NTarget_g_tc;
                }

                NTarget_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                NTarget_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< usmallint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                NTarget_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                NTarget_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                NTarget_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                NTarget_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                NTarget_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                NTarget_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                NTarget_g_tc._data._sampleAccessInfo = sample_access_info();
                NTarget_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &NTarget_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::NTarget *sample;

                static RTIXCdrMemberAccessInfo NTarget_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo NTarget_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &NTarget_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::NTarget);
                if (sample == NULL) {
                    return NULL;
                }

                NTarget_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->_NTarget() - (char *)sample);

                NTarget_g_sampleAccessInfo.memberAccessInfos = 
                NTarget_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::NTarget);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        NTarget_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        NTarget_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                NTarget_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                NTarget_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::NTarget >;

                NTarget_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &NTarget_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin NTarget_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &NTarget_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::NTarget >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::NTarget >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[8]=
                {

                    {
                        (char *)"roiAx",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiAy",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBx",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiBy",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCx",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiCy",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDx",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"roiDy",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*/

                if (is_initialized) {
                    return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc;
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< _cxx_int_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._defaultValue._u.long_value = 0;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc_members[7]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._sampleAccessInfo = sample_access_info();
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample;

                static RTIXCdrMemberAccessInfo roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);
                if (sample == NULL) {
                    return NULL;
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiAy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiBy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiCy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDx() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->roiDy() - (char *)sample);

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.memberAccessInfos = 
                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >;

                roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode flgShiftScoreMinScoreMax_g_tc_flg_sequence;

                static DDS_TypeCode_Member flgShiftScoreMinScoreMax_g_tc_members[4]=
                {

                    {
                        (char *)"flg",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"shift",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"scoreMin",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"scoreMax",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode flgShiftScoreMinScoreMax_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskIprCorner::flgShiftScoreMinScoreMax", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        flgShiftScoreMinScoreMax_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for flgShiftScoreMinScoreMax*/

                if (is_initialized) {
                    return &flgShiftScoreMinScoreMax_g_tc;
                }

                flgShiftScoreMinScoreMax_g_tc_flg_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< bool, 786432 > >((786432));

                flgShiftScoreMinScoreMax_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                flgShiftScoreMinScoreMax_g_tc_flg_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                flgShiftScoreMinScoreMax_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& flgShiftScoreMinScoreMax_g_tc_flg_sequence;
                flgShiftScoreMinScoreMax_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();
                flgShiftScoreMinScoreMax_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();
                flgShiftScoreMinScoreMax_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< utinyint_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */

                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._defaultValue._u.octet_value = 0;
                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                flgShiftScoreMinScoreMax_g_tc_members[3]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                flgShiftScoreMinScoreMax_g_tc._data._sampleAccessInfo = sample_access_info();
                flgShiftScoreMinScoreMax_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &flgShiftScoreMinScoreMax_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskIprCorner::flgShiftScoreMinScoreMax *sample;

                static RTIXCdrMemberAccessInfo flgShiftScoreMinScoreMax_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo flgShiftScoreMinScoreMax_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &flgShiftScoreMinScoreMax_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskIprCorner::flgShiftScoreMinScoreMax);
                if (sample == NULL) {
                    return NULL;
                }

                flgShiftScoreMinScoreMax_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->flg() - (char *)sample);

                flgShiftScoreMinScoreMax_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->shift() - (char *)sample);

                flgShiftScoreMinScoreMax_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->scoreMin() - (char *)sample);

                flgShiftScoreMinScoreMax_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->scoreMax() - (char *)sample);

                flgShiftScoreMinScoreMax_g_sampleAccessInfo.memberAccessInfos = 
                flgShiftScoreMinScoreMax_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskIprCorner::flgShiftScoreMinScoreMax);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        flgShiftScoreMinScoreMax_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        flgShiftScoreMinScoreMax_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                flgShiftScoreMinScoreMax_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                flgShiftScoreMinScoreMax_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >;

                flgShiftScoreMinScoreMax_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &flgShiftScoreMinScoreMax_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin flgShiftScoreMinScoreMax_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &flgShiftScoreMinScoreMax_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::moveto_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member moveto_req_g_tc_members[1]=
                {

                    {
                        (char *)"target",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode moveto_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::moveto_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        moveto_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for moveto_req*/

                if (is_initialized) {
                    return &moveto_req_g_tc;
                }

                moveto_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                moveto_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                moveto_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                moveto_req_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                moveto_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                moveto_req_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                moveto_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                moveto_req_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                moveto_req_g_tc._data._sampleAccessInfo = sample_access_info();
                moveto_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &moveto_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::moveto_req *sample;

                static RTIXCdrMemberAccessInfo moveto_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo moveto_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &moveto_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::moveto_req);
                if (sample == NULL) {
                    return NULL;
                }

                moveto_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->target() - (char *)sample);

                moveto_req_g_sampleAccessInfo.memberAccessInfos = 
                moveto_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::moveto_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        moveto_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        moveto_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                moveto_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                moveto_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::moveto_req >;

                moveto_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &moveto_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin moveto_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &moveto_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::moveto_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::moveto_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::moveto_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member moveto_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode moveto_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::moveto_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        moveto_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for moveto_reply*/

                if (is_initialized) {
                    return &moveto_reply_g_tc;
                }

                moveto_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                moveto_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                moveto_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                moveto_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                moveto_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                moveto_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &moveto_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::moveto_reply *sample;

                static RTIXCdrMemberAccessInfo moveto_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo moveto_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &moveto_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::moveto_reply);
                if (sample == NULL) {
                    return NULL;
                }

                moveto_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                moveto_reply_g_sampleAccessInfo.memberAccessInfos = 
                moveto_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::moveto_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        moveto_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        moveto_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                moveto_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                moveto_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::moveto_reply >;

                moveto_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &moveto_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin moveto_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &moveto_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::moveto_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::moveto_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::stop_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode stop_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::stop_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for stop_req*/

                if (is_initialized) {
                    return &stop_req_g_tc;
                }

                stop_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                stop_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                stop_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                stop_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                stop_req_g_tc._data._sampleAccessInfo = sample_access_info();
                stop_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &stop_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::stop_req *sample;

                static RTIXCdrMemberAccessInfo stop_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo stop_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &stop_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::stop_req);
                if (sample == NULL) {
                    return NULL;
                }

                stop_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->dummy() - (char *)sample);

                stop_req_g_sampleAccessInfo.memberAccessInfos = 
                stop_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::stop_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        stop_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        stop_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                stop_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                stop_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::stop_req >;

                stop_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &stop_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin stop_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &stop_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::stop_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::stop_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::stop_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member stop_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode stop_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::stop_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        stop_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for stop_reply*/

                if (is_initialized) {
                    return &stop_reply_g_tc;
                }

                stop_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                stop_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                stop_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                stop_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                stop_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                stop_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &stop_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::stop_reply *sample;

                static RTIXCdrMemberAccessInfo stop_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo stop_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &stop_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::stop_reply);
                if (sample == NULL) {
                    return NULL;
                }

                stop_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                stop_reply_g_sampleAccessInfo.memberAccessInfos = 
                stop_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::stop_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        stop_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        stop_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                stop_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                stop_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::stop_reply >;

                stop_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &stop_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin stop_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &stop_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::stop_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::stop_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::turn_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member turn_req_g_tc_members[1]=
                {

                    {
                        (char *)"ccwNotCw",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode turn_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::turn_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        turn_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for turn_req*/

                if (is_initialized) {
                    return &turn_req_g_tc;
                }

                turn_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                turn_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                turn_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                turn_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                turn_req_g_tc._data._sampleAccessInfo = sample_access_info();
                turn_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &turn_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::turn_req *sample;

                static RTIXCdrMemberAccessInfo turn_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo turn_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &turn_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::turn_req);
                if (sample == NULL) {
                    return NULL;
                }

                turn_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ccwNotCw() - (char *)sample);

                turn_req_g_sampleAccessInfo.memberAccessInfos = 
                turn_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::turn_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        turn_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        turn_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                turn_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                turn_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::turn_req >;

                turn_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &turn_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin turn_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &turn_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::turn_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::turn_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::turn_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member turn_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode turn_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::turn_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        turn_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for turn_reply*/

                if (is_initialized) {
                    return &turn_reply_g_tc;
                }

                turn_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                turn_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                turn_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                turn_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                turn_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                turn_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &turn_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::turn_reply *sample;

                static RTIXCdrMemberAccessInfo turn_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo turn_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &turn_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::turn_reply);
                if (sample == NULL) {
                    return NULL;
                }

                turn_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                turn_reply_g_sampleAccessInfo.memberAccessInfos = 
                turn_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::turn_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        turn_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        turn_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                turn_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                turn_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::turn_reply >;

                turn_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &turn_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin turn_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &turn_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::turn_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::turn_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::zero_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member zero_req_g_tc_members[1]=
                {

                    {
                        (char *)"dummy",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode zero_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::zero_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        zero_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for zero_req*/

                if (is_initialized) {
                    return &zero_req_g_tc;
                }

                zero_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                zero_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                zero_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                zero_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                zero_req_g_tc._data._sampleAccessInfo = sample_access_info();
                zero_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &zero_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::zero_req *sample;

                static RTIXCdrMemberAccessInfo zero_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo zero_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &zero_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::zero_req);
                if (sample == NULL) {
                    return NULL;
                }

                zero_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->dummy() - (char *)sample);

                zero_req_g_sampleAccessInfo.memberAccessInfos = 
                zero_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::zero_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        zero_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        zero_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                zero_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                zero_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::zero_req >;

                zero_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &zero_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin zero_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &zero_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::zero_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::zero_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::zero_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member zero_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode zero_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::zero_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        zero_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for zero_reply*/

                if (is_initialized) {
                    return &zero_reply_g_tc;
                }

                zero_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                zero_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                zero_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                zero_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                zero_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                zero_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &zero_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::zero_reply *sample;

                static RTIXCdrMemberAccessInfo zero_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo zero_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &zero_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::zero_reply);
                if (sample == NULL) {
                    return NULL;
                }

                zero_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                zero_reply_g_sampleAccessInfo.memberAccessInfos = 
                zero_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::zero_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        zero_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        zero_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                zero_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                zero_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::zero_reply >;

                zero_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &zero_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin zero_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &zero_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::zero_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::zero_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActServo::angleTarget > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member angleTarget_g_tc_members[2]=
                {

                    {
                        (char *)"angle",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"target",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode angleTarget_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActServo::angleTarget", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        angleTarget_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for angleTarget*/

                if (is_initialized) {
                    return &angleTarget_g_tc;
                }

                angleTarget_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                angleTarget_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                angleTarget_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                angleTarget_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                angleTarget_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                angleTarget_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                angleTarget_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                angleTarget_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                angleTarget_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                angleTarget_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                angleTarget_g_tc._data._sampleAccessInfo = sample_access_info();
                angleTarget_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &angleTarget_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActServo::angleTarget *sample;

                static RTIXCdrMemberAccessInfo angleTarget_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo angleTarget_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &angleTarget_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActServo::angleTarget);
                if (sample == NULL) {
                    return NULL;
                }

                angleTarget_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->angle() - (char *)sample);

                angleTarget_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->target() - (char *)sample);

                angleTarget_g_sampleAccessInfo.memberAccessInfos = 
                angleTarget_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActServo::angleTarget);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        angleTarget_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        angleTarget_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                angleTarget_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                angleTarget_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActServo::angleTarget >;

                angleTarget_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &angleTarget_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin angleTarget_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &angleTarget_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActServo::angleTarget >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActServo::angleTarget >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActLaser::setLeft_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setLeft_req_g_tc_members[1]=
                {

                    {
                        (char *)"left",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setLeft_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActLaser::setLeft_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setLeft_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setLeft_req*/

                if (is_initialized) {
                    return &setLeft_req_g_tc;
                }

                setLeft_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setLeft_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                setLeft_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                setLeft_req_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                setLeft_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                setLeft_req_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                setLeft_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                setLeft_req_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                setLeft_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setLeft_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setLeft_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActLaser::setLeft_req *sample;

                static RTIXCdrMemberAccessInfo setLeft_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setLeft_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setLeft_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActLaser::setLeft_req);
                if (sample == NULL) {
                    return NULL;
                }

                setLeft_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->left() - (char *)sample);

                setLeft_req_g_sampleAccessInfo.memberAccessInfos = 
                setLeft_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActLaser::setLeft_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setLeft_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setLeft_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setLeft_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setLeft_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActLaser::setLeft_req >;

                setLeft_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setLeft_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setLeft_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setLeft_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActLaser::setLeft_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActLaser::setLeft_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActLaser::setLeft_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setLeft_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setLeft_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActLaser::setLeft_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setLeft_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setLeft_reply*/

                if (is_initialized) {
                    return &setLeft_reply_g_tc;
                }

                setLeft_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setLeft_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setLeft_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setLeft_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setLeft_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setLeft_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setLeft_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActLaser::setLeft_reply *sample;

                static RTIXCdrMemberAccessInfo setLeft_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setLeft_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setLeft_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActLaser::setLeft_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setLeft_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setLeft_reply_g_sampleAccessInfo.memberAccessInfos = 
                setLeft_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActLaser::setLeft_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setLeft_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setLeft_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setLeft_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setLeft_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActLaser::setLeft_reply >;

                setLeft_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setLeft_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setLeft_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setLeft_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActLaser::setLeft_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActLaser::setLeft_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActLaser::setRight_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRight_req_g_tc_members[1]=
                {

                    {
                        (char *)"right",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRight_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActLaser::setRight_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRight_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRight_req*/

                if (is_initialized) {
                    return &setRight_req_g_tc;
                }

                setRight_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRight_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                setRight_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                setRight_req_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                setRight_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                setRight_req_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                setRight_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                setRight_req_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                setRight_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setRight_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRight_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActLaser::setRight_req *sample;

                static RTIXCdrMemberAccessInfo setRight_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRight_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRight_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActLaser::setRight_req);
                if (sample == NULL) {
                    return NULL;
                }

                setRight_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->right() - (char *)sample);

                setRight_req_g_sampleAccessInfo.memberAccessInfos = 
                setRight_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActLaser::setRight_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRight_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRight_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRight_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRight_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActLaser::setRight_req >;

                setRight_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRight_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRight_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRight_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActLaser::setRight_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActLaser::setRight_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActLaser::setRight_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setRight_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setRight_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActLaser::setRight_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setRight_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setRight_reply*/

                if (is_initialized) {
                    return &setRight_reply_g_tc;
                }

                setRight_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setRight_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setRight_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setRight_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setRight_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setRight_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setRight_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActLaser::setRight_reply *sample;

                static RTIXCdrMemberAccessInfo setRight_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setRight_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setRight_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActLaser::setRight_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setRight_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setRight_reply_g_sampleAccessInfo.memberAccessInfos = 
                setRight_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActLaser::setRight_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setRight_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setRight_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setRight_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setRight_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActLaser::setRight_reply >;

                setRight_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setRight_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setRight_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setRight_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActLaser::setRight_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActLaser::setRight_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActLaser::leftRight > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member leftRight_g_tc_members[2]=
                {

                    {
                        (char *)"left",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"right",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode leftRight_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActLaser::leftRight", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        leftRight_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for leftRight*/

                if (is_initialized) {
                    return &leftRight_g_tc;
                }

                leftRight_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                leftRight_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                leftRight_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                leftRight_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                leftRight_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                leftRight_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                leftRight_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                leftRight_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                leftRight_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                leftRight_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                leftRight_g_tc._data._sampleAccessInfo = sample_access_info();
                leftRight_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &leftRight_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActLaser::leftRight *sample;

                static RTIXCdrMemberAccessInfo leftRight_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo leftRight_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &leftRight_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActLaser::leftRight);
                if (sample == NULL) {
                    return NULL;
                }

                leftRight_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->left() - (char *)sample);

                leftRight_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->right() - (char *)sample);

                leftRight_g_sampleAccessInfo.memberAccessInfos = 
                leftRight_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActLaser::leftRight);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        leftRight_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        leftRight_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                leftRight_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                leftRight_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActLaser::leftRight >;

                leftRight_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &leftRight_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin leftRight_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &leftRight_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActLaser::leftRight >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActLaser::leftRight >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::setExposure_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setExposure_req_g_tc_members[2]=
                {

                    {
                        (char *)"autoNotManual",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Texp",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setExposure_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::setExposure_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        setExposure_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setExposure_req*/

                if (is_initialized) {
                    return &setExposure_req_g_tc;
                }

                setExposure_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setExposure_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                setExposure_req_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                setExposure_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setExposure_req_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setExposure_req_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                setExposure_req_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                setExposure_req_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                setExposure_req_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                setExposure_req_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                setExposure_req_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                setExposure_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setExposure_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setExposure_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::setExposure_req *sample;

                static RTIXCdrMemberAccessInfo setExposure_req_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setExposure_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setExposure_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::setExposure_req);
                if (sample == NULL) {
                    return NULL;
                }

                setExposure_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->autoNotManual() - (char *)sample);

                setExposure_req_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Texp() - (char *)sample);

                setExposure_req_g_sampleAccessInfo.memberAccessInfos = 
                setExposure_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::setExposure_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setExposure_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setExposure_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setExposure_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setExposure_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::setExposure_req >;

                setExposure_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setExposure_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setExposure_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setExposure_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::setExposure_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::setExposure_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::setExposure_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setExposure_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setExposure_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::setExposure_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setExposure_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setExposure_reply*/

                if (is_initialized) {
                    return &setExposure_reply_g_tc;
                }

                setExposure_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setExposure_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setExposure_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setExposure_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setExposure_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setExposure_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setExposure_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::setExposure_reply *sample;

                static RTIXCdrMemberAccessInfo setExposure_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setExposure_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setExposure_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::setExposure_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setExposure_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setExposure_reply_g_sampleAccessInfo.memberAccessInfos = 
                setExposure_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::setExposure_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setExposure_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setExposure_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setExposure_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setExposure_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::setExposure_reply >;

                setExposure_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setExposure_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setExposure_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setExposure_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::setExposure_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::setExposure_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::setFocus_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_req_g_tc_members[1]=
                {

                    {
                        (char *)"focus",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setFocus_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::setFocus_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setFocus_req*/

                if (is_initialized) {
                    return &setFocus_req_g_tc;
                }

                setFocus_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setFocus_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                setFocus_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                setFocus_req_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                setFocus_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                setFocus_req_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                setFocus_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                setFocus_req_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                setFocus_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setFocus_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setFocus_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::setFocus_req *sample;

                static RTIXCdrMemberAccessInfo setFocus_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setFocus_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setFocus_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::setFocus_req);
                if (sample == NULL) {
                    return NULL;
                }

                setFocus_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->focus() - (char *)sample);

                setFocus_req_g_sampleAccessInfo.memberAccessInfos = 
                setFocus_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::setFocus_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setFocus_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setFocus_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setFocus_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setFocus_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::setFocus_req >;

                setFocus_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setFocus_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setFocus_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setFocus_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::setFocus_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::setFocus_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::setFocus_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setFocus_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setFocus_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::setFocus_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setFocus_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setFocus_reply*/

                if (is_initialized) {
                    return &setFocus_reply_g_tc;
                }

                setFocus_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setFocus_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setFocus_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setFocus_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setFocus_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setFocus_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setFocus_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::setFocus_reply *sample;

                static RTIXCdrMemberAccessInfo setFocus_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setFocus_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setFocus_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::setFocus_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setFocus_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setFocus_reply_g_sampleAccessInfo.memberAccessInfos = 
                setFocus_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::setFocus_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setFocus_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setFocus_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setFocus_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setFocus_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::setFocus_reply >;

                setFocus_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setFocus_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setFocus_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setFocus_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::setFocus_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::setFocus_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::autoNotManualTexp > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member autoNotManualTexp_g_tc_members[2]=
                {

                    {
                        (char *)"autoNotManual",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Texp",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode autoNotManualTexp_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::autoNotManualTexp", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        autoNotManualTexp_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for autoNotManualTexp*/

                if (is_initialized) {
                    return &autoNotManualTexp_g_tc;
                }

                autoNotManualTexp_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                autoNotManualTexp_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                autoNotManualTexp_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                autoNotManualTexp_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                autoNotManualTexp_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                autoNotManualTexp_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                autoNotManualTexp_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
                autoNotManualTexp_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                autoNotManualTexp_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                autoNotManualTexp_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                autoNotManualTexp_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                autoNotManualTexp_g_tc._data._sampleAccessInfo = sample_access_info();
                autoNotManualTexp_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &autoNotManualTexp_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::autoNotManualTexp *sample;

                static RTIXCdrMemberAccessInfo autoNotManualTexp_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo autoNotManualTexp_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &autoNotManualTexp_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::autoNotManualTexp);
                if (sample == NULL) {
                    return NULL;
                }

                autoNotManualTexp_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->autoNotManual() - (char *)sample);

                autoNotManualTexp_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Texp() - (char *)sample);

                autoNotManualTexp_g_sampleAccessInfo.memberAccessInfos = 
                autoNotManualTexp_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::autoNotManualTexp);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        autoNotManualTexp_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        autoNotManualTexp_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                autoNotManualTexp_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                autoNotManualTexp_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::autoNotManualTexp >;

                autoNotManualTexp_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &autoNotManualTexp_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin autoNotManualTexp_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &autoNotManualTexp_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::autoNotManualTexp >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::autoNotManualTexp >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskActExposure::focus > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member focus_g_tc_members[1]=
                {

                    {
                        (char *)"_focus",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode focus_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskActExposure::focus", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        focus_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for focus*/

                if (is_initialized) {
                    return &focus_g_tc;
                }

                focus_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                focus_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                focus_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                focus_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                focus_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                focus_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                focus_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                focus_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                focus_g_tc._data._sampleAccessInfo = sample_access_info();
                focus_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &focus_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskActExposure::focus *sample;

                static RTIXCdrMemberAccessInfo focus_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo focus_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &focus_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskActExposure::focus);
                if (sample == NULL) {
                    return NULL;
                }

                focus_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->_focus() - (char *)sample);

                focus_g_sampleAccessInfo.memberAccessInfos = 
                focus_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskActExposure::focus);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        focus_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        focus_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                focus_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                focus_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskActExposure::focus >;

                focus_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &focus_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin focus_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &focus_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskActExposure::focus >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskActExposure::focus >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPtcloud::setDeltaTheta_req > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setDeltaTheta_req_g_tc_members[1]=
                {

                    {
                        (char *)"deltaTheta",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setDeltaTheta_req_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPtcloud::setDeltaTheta_req", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setDeltaTheta_req_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setDeltaTheta_req*/

                if (is_initialized) {
                    return &setDeltaTheta_req_g_tc;
                }

                setDeltaTheta_req_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setDeltaTheta_req_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                setDeltaTheta_req_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                setDeltaTheta_req_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                setDeltaTheta_req_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                setDeltaTheta_req_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                setDeltaTheta_req_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                setDeltaTheta_req_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                setDeltaTheta_req_g_tc._data._sampleAccessInfo = sample_access_info();
                setDeltaTheta_req_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setDeltaTheta_req_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPtcloud::setDeltaTheta_req *sample;

                static RTIXCdrMemberAccessInfo setDeltaTheta_req_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setDeltaTheta_req_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setDeltaTheta_req_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPtcloud::setDeltaTheta_req);
                if (sample == NULL) {
                    return NULL;
                }

                setDeltaTheta_req_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->deltaTheta() - (char *)sample);

                setDeltaTheta_req_g_sampleAccessInfo.memberAccessInfos = 
                setDeltaTheta_req_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPtcloud::setDeltaTheta_req);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setDeltaTheta_req_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setDeltaTheta_req_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setDeltaTheta_req_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setDeltaTheta_req_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPtcloud::setDeltaTheta_req >;

                setDeltaTheta_req_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setDeltaTheta_req_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setDeltaTheta_req_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setDeltaTheta_req_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPtcloud::setDeltaTheta_reply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member setDeltaTheta_reply_g_tc_members[1]=
                {

                    {
                        (char *)"success",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode setDeltaTheta_reply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPtcloud::setDeltaTheta_reply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        setDeltaTheta_reply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for setDeltaTheta_reply*/

                if (is_initialized) {
                    return &setDeltaTheta_reply_g_tc;
                }

                setDeltaTheta_reply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                setDeltaTheta_reply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                setDeltaTheta_reply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                setDeltaTheta_reply_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                setDeltaTheta_reply_g_tc._data._sampleAccessInfo = sample_access_info();
                setDeltaTheta_reply_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &setDeltaTheta_reply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPtcloud::setDeltaTheta_reply *sample;

                static RTIXCdrMemberAccessInfo setDeltaTheta_reply_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo setDeltaTheta_reply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &setDeltaTheta_reply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPtcloud::setDeltaTheta_reply);
                if (sample == NULL) {
                    return NULL;
                }

                setDeltaTheta_reply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->success() - (char *)sample);

                setDeltaTheta_reply_g_sampleAccessInfo.memberAccessInfos = 
                setDeltaTheta_reply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPtcloud::setDeltaTheta_reply);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        setDeltaTheta_reply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        setDeltaTheta_reply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                setDeltaTheta_reply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                setDeltaTheta_reply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >;

                setDeltaTheta_reply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &setDeltaTheta_reply_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin setDeltaTheta_reply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &setDeltaTheta_reply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPtcloud::deltaTheta > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member deltaTheta_g_tc_members[1]=
                {

                    {
                        (char *)"_deltaTheta",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode deltaTheta_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPtcloud::deltaTheta", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        deltaTheta_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for deltaTheta*/

                if (is_initialized) {
                    return &deltaTheta_g_tc;
                }

                deltaTheta_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                deltaTheta_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                deltaTheta_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                deltaTheta_g_tc_members[0]._annotations._defaultValue._u.float_value = 0.0f;
                deltaTheta_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                deltaTheta_g_tc_members[0]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                deltaTheta_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                deltaTheta_g_tc_members[0]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                deltaTheta_g_tc._data._sampleAccessInfo = sample_access_info();
                deltaTheta_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &deltaTheta_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPtcloud::deltaTheta *sample;

                static RTIXCdrMemberAccessInfo deltaTheta_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo deltaTheta_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &deltaTheta_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPtcloud::deltaTheta);
                if (sample == NULL) {
                    return NULL;
                }

                deltaTheta_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->_deltaTheta() - (char *)sample);

                deltaTheta_g_sampleAccessInfo.memberAccessInfos = 
                deltaTheta_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPtcloud::deltaTheta);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        deltaTheta_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        deltaTheta_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                deltaTheta_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                deltaTheta_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPtcloud::deltaTheta >;

                deltaTheta_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &deltaTheta_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin deltaTheta_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &deltaTheta_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPtcloud::deltaTheta >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPtcloud::deltaTheta >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPtcloud::xYZ > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode xYZ_g_tc_x_sequence;
                static DDS_TypeCode xYZ_g_tc_y_sequence;
                static DDS_TypeCode xYZ_g_tc_z_sequence;

                static DDS_TypeCode_Member xYZ_g_tc_members[3]=
                {

                    {
                        (char *)"x",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"y",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"z",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode xYZ_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPtcloud::xYZ", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        xYZ_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for xYZ*/

                if (is_initialized) {
                    return &xYZ_g_tc;
                }

                xYZ_g_tc_x_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 72000 > >((72000));
                xYZ_g_tc_y_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 72000 > >((72000));
                xYZ_g_tc_z_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, 72000 > >((72000));

                xYZ_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                xYZ_g_tc_x_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                xYZ_g_tc_y_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                xYZ_g_tc_z_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                xYZ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& xYZ_g_tc_x_sequence;
                xYZ_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& xYZ_g_tc_y_sequence;
                xYZ_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& xYZ_g_tc_z_sequence;

                /* Initialize the values for member annotations. */

                xYZ_g_tc._data._sampleAccessInfo = sample_access_info();
                xYZ_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &xYZ_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPtcloud::xYZ *sample;

                static RTIXCdrMemberAccessInfo xYZ_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo xYZ_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &xYZ_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPtcloud::xYZ);
                if (sample == NULL) {
                    return NULL;
                }

                xYZ_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->x() - (char *)sample);

                xYZ_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->y() - (char *)sample);

                xYZ_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->z() - (char *)sample);

                xYZ_g_sampleAccessInfo.memberAccessInfos = 
                xYZ_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPtcloud::xYZ);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        xYZ_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        xYZ_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                xYZ_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                xYZ_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPtcloud::xYZ >;

                xYZ_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &xYZ_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin xYZ_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &xYZ_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPtcloud::xYZ >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPtcloud::xYZ >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPreview::gray > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode gray_g_tc__gray_sequence;

                static DDS_TypeCode_Member gray_g_tc_members[1]=
                {

                    {
                        (char *)"_gray",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode gray_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPreview::gray", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        gray_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for gray*/

                if (is_initialized) {
                    return &gray_g_tc;
                }

                gray_g_tc__gray_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, 49152 > >((49152));

                gray_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                gray_g_tc__gray_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                gray_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& gray_g_tc__gray_sequence;

                /* Initialize the values for member annotations. */

                gray_g_tc._data._sampleAccessInfo = sample_access_info();
                gray_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &gray_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPreview::gray *sample;

                static RTIXCdrMemberAccessInfo gray_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo gray_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &gray_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPreview::gray);
                if (sample == NULL) {
                    return NULL;
                }

                gray_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->_gray() - (char *)sample);

                gray_g_sampleAccessInfo.memberAccessInfos = 
                gray_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPreview::gray);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        gray_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        gray_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                gray_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                gray_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPreview::gray >;

                gray_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &gray_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin gray_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &gray_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPreview::gray >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPreview::gray >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE

        template<>
        struct native_type_code< DdsJobWzskAcqPreview::redGreenBlue > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode redGreenBlue_g_tc_red_sequence;
                static DDS_TypeCode redGreenBlue_g_tc_green_sequence;
                static DDS_TypeCode redGreenBlue_g_tc_blue_sequence;

                static DDS_TypeCode_Member redGreenBlue_g_tc_members[3]=
                {

                    {
                        (char *)"red",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"green",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"blue",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode redGreenBlue_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DdsJobWzskAcqPreview::redGreenBlue", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        redGreenBlue_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for redGreenBlue*/

                if (is_initialized) {
                    return &redGreenBlue_g_tc;
                }

                redGreenBlue_g_tc_red_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, 19200 > >((19200));
                redGreenBlue_g_tc_green_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, 19200 > >((19200));
                redGreenBlue_g_tc_blue_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, 19200 > >((19200));

                redGreenBlue_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                redGreenBlue_g_tc_red_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                redGreenBlue_g_tc_green_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                redGreenBlue_g_tc_blue_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                redGreenBlue_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& redGreenBlue_g_tc_red_sequence;
                redGreenBlue_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& redGreenBlue_g_tc_green_sequence;
                redGreenBlue_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& redGreenBlue_g_tc_blue_sequence;

                /* Initialize the values for member annotations. */

                redGreenBlue_g_tc._data._sampleAccessInfo = sample_access_info();
                redGreenBlue_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &redGreenBlue_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DdsJobWzskAcqPreview::redGreenBlue *sample;

                static RTIXCdrMemberAccessInfo redGreenBlue_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo redGreenBlue_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &redGreenBlue_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DdsJobWzskAcqPreview::redGreenBlue);
                if (sample == NULL) {
                    return NULL;
                }

                redGreenBlue_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->red() - (char *)sample);

                redGreenBlue_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->green() - (char *)sample);

                redGreenBlue_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->blue() - (char *)sample);

                redGreenBlue_g_sampleAccessInfo.memberAccessInfos = 
                redGreenBlue_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DdsJobWzskAcqPreview::redGreenBlue);

                    if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                        redGreenBlue_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrUnsignedLong_MAX;
                    } else {
                        redGreenBlue_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                redGreenBlue_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                redGreenBlue_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DdsJobWzskAcqPreview::redGreenBlue >;

                redGreenBlue_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &redGreenBlue_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin redGreenBlue_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &redGreenBlue_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DdsJobWzskAcqPreview::redGreenBlue >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DdsJobWzskAcqPreview::redGreenBlue >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< DdsFloatmat >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsFloatmatPlugin_new,
                DdsFloatmatPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsFloatmat >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsFloatmat& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DdsFloatmatPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DdsFloatmatPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsFloatmat >::from_cdr_buffer(DdsFloatmat& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DdsFloatmatPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsFloatmat from cdr buffer");
        }

        void topic_type_support< DdsFloatmat >::reset_sample(DdsFloatmat& sample) 
        {
            ::rti::topic::reset_sample(sample.vec());
            sample.M(0u);
            sample.N(0u);
        }

        void topic_type_support< DdsFloatmat >::allocate_sample(DdsFloatmat& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.vec(),  100, -1);
        }

        void topic_type_support< DdsDoublemat >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsDoublematPlugin_new,
                DdsDoublematPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsDoublemat >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsDoublemat& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DdsDoublematPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DdsDoublematPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsDoublemat >::from_cdr_buffer(DdsDoublemat& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DdsDoublematPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsDoublemat from cdr buffer");
        }

        void topic_type_support< DdsDoublemat >::reset_sample(DdsDoublemat& sample) 
        {
            ::rti::topic::reset_sample(sample.vec());
            sample.M(0u);
            sample.N(0u);
        }

        void topic_type_support< DdsDoublemat >::allocate_sample(DdsDoublemat& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.vec(),  100, -1);
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_new,
                DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::from_cdr_buffer(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 from cdr buffer");
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::reset_sample(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample) 
        {
            ::rti::topic::reset_sample(sample.loadAll());
            ::rti::topic::reset_sample(sample.loadCore0());
            ::rti::topic::reset_sample(sample.loadCore1());
            ::rti::topic::reset_sample(sample.loadCore2());
            ::rti::topic::reset_sample(sample.loadCore3());
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3 >::allocate_sample(DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.loadAll(),  60, -1);
            ::rti::topic::allocate_sample(sample.loadCore0(),  60, -1);
            ::rti::topic::allocate_sample(sample.loadCore1(),  60, -1);
            ::rti::topic::allocate_sample(sample.loadCore2(),  60, -1);
            ::rti::topic::allocate_sample(sample.loadCore3(),  60, -1);
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::temp >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskSrcSysinfo::tempPlugin_new,
                DdsJobWzskSrcSysinfo::tempPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskSrcSysinfo::temp >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskSrcSysinfo::temp& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = tempPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = tempPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::temp >::from_cdr_buffer(DdsJobWzskSrcSysinfo::temp& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = tempPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskSrcSysinfo::temp from cdr buffer");
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::temp >::reset_sample(DdsJobWzskSrcSysinfo::temp& sample) 
        {
            ::rti::topic::reset_sample(sample._temp());
        }

        void topic_type_support< DdsJobWzskSrcSysinfo::temp >::allocate_sample(DdsJobWzskSrcSysinfo::temp& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample._temp(),  60, -1);
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setLevel_reqPlugin_new,
                DdsJobWzskIprTrace::setLevel_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setLevel_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setLevel_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setLevel_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setLevel_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_req >::from_cdr_buffer(DdsJobWzskIprTrace::setLevel_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setLevel_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setLevel_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_req >::reset_sample(DdsJobWzskIprTrace::setLevel_req& sample) 
        {
            sample.levelOn(0);
            sample.levelOff(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_req >::allocate_sample(DdsJobWzskIprTrace::setLevel_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setLevel_replyPlugin_new,
                DdsJobWzskIprTrace::setLevel_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setLevel_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setLevel_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setLevel_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setLevel_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_reply >::from_cdr_buffer(DdsJobWzskIprTrace::setLevel_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setLevel_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setLevel_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_reply >::reset_sample(DdsJobWzskIprTrace::setLevel_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setLevel_reply >::allocate_sample(DdsJobWzskIprTrace::setLevel_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setRoi_reqPlugin_new,
                DdsJobWzskIprTrace::setRoi_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setRoi_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setRoi_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoi_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoi_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_req >::from_cdr_buffer(DdsJobWzskIprTrace::setRoi_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoi_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setRoi_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_req >::reset_sample(DdsJobWzskIprTrace::setRoi_req& sample) 
        {
            sample.roiAx(0);
            sample.roiAy(0);
            sample.roiBx(0);
            sample.roiBy(0);
            sample.roiCx(0);
            sample.roiCy(0);
            sample.roiDx(0);
            sample.roiDy(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_req >::allocate_sample(DdsJobWzskIprTrace::setRoi_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setRoi_replyPlugin_new,
                DdsJobWzskIprTrace::setRoi_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setRoi_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setRoi_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoi_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoi_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_reply >::from_cdr_buffer(DdsJobWzskIprTrace::setRoi_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoi_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setRoi_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_reply >::reset_sample(DdsJobWzskIprTrace::setRoi_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoi_reply >::allocate_sample(DdsJobWzskIprTrace::setRoi_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setRoiNotFull_reqPlugin_new,
                DdsJobWzskIprTrace::setRoiNotFull_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setRoiNotFull_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req >::from_cdr_buffer(DdsJobWzskIprTrace::setRoiNotFull_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoiNotFull_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setRoiNotFull_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req >::reset_sample(DdsJobWzskIprTrace::setRoiNotFull_req& sample) 
        {
            sample.roiNotFull(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_req >::allocate_sample(DdsJobWzskIprTrace::setRoiNotFull_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::setRoiNotFull_replyPlugin_new,
                DdsJobWzskIprTrace::setRoiNotFull_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::setRoiNotFull_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply >::from_cdr_buffer(DdsJobWzskIprTrace::setRoiNotFull_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoiNotFull_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::setRoiNotFull_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply >::reset_sample(DdsJobWzskIprTrace::setRoiNotFull_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::setRoiNotFull_reply >::allocate_sample(DdsJobWzskIprTrace::setRoiNotFull_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::pOnLeftPOnRightPlugin_new,
                DdsJobWzskIprTrace::pOnLeftPOnRightPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::pOnLeftPOnRight& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = pOnLeftPOnRightPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = pOnLeftPOnRightPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight >::from_cdr_buffer(DdsJobWzskIprTrace::pOnLeftPOnRight& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = pOnLeftPOnRightPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::pOnLeftPOnRight from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight >::reset_sample(DdsJobWzskIprTrace::pOnLeftPOnRight& sample) 
        {
            sample.pOnLeft(0.0f);
            sample.pOnRight(0.0f);
        }

        void topic_type_support< DdsJobWzskIprTrace::pOnLeftPOnRight >::allocate_sample(DdsJobWzskIprTrace::pOnLeftPOnRight& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::levelOnLevelOffPlugin_new,
                DdsJobWzskIprTrace::levelOnLevelOffPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::levelOnLevelOff& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = levelOnLevelOffPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = levelOnLevelOffPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff >::from_cdr_buffer(DdsJobWzskIprTrace::levelOnLevelOff& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = levelOnLevelOffPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::levelOnLevelOff from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff >::reset_sample(DdsJobWzskIprTrace::levelOnLevelOff& sample) 
        {
            sample.levelOn(0);
            sample.levelOff(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::levelOnLevelOff >::allocate_sample(DdsJobWzskIprTrace::levelOnLevelOff& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_new,
                DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::from_cdr_buffer(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::reset_sample(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample) 
        {
            sample.roiAx(0);
            sample.roiAy(0);
            sample.roiBx(0);
            sample.roiBy(0);
            sample.roiCx(0);
            sample.roiCy(0);
            sample.roiDx(0);
            sample.roiDy(0);
        }

        void topic_type_support< DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::allocate_sample(DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprTrace::leftRight >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprTrace::leftRightPlugin_new,
                DdsJobWzskIprTrace::leftRightPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprTrace::leftRight >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprTrace::leftRight& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = leftRightPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = leftRightPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprTrace::leftRight >::from_cdr_buffer(DdsJobWzskIprTrace::leftRight& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = leftRightPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprTrace::leftRight from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprTrace::leftRight >::reset_sample(DdsJobWzskIprTrace::leftRight& sample) 
        {
            ::rti::topic::reset_sample(sample.left());
            ::rti::topic::reset_sample(sample.right());
        }

        void topic_type_support< DdsJobWzskIprTrace::leftRight >::allocate_sample(DdsJobWzskIprTrace::leftRight& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.left(),  786432, -1);
            ::rti::topic::allocate_sample(sample.right(),  786432, -1);
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setNTarget_reqPlugin_new,
                DdsJobWzskIprCorner::setNTarget_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setNTarget_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setNTarget_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setNTarget_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setNTarget_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_req >::from_cdr_buffer(DdsJobWzskIprCorner::setNTarget_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setNTarget_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setNTarget_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_req >::reset_sample(DdsJobWzskIprCorner::setNTarget_req& sample) 
        {
            sample.NTarget(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_req >::allocate_sample(DdsJobWzskIprCorner::setNTarget_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setNTarget_replyPlugin_new,
                DdsJobWzskIprCorner::setNTarget_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setNTarget_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setNTarget_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setNTarget_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setNTarget_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_reply >::from_cdr_buffer(DdsJobWzskIprCorner::setNTarget_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setNTarget_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setNTarget_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_reply >::reset_sample(DdsJobWzskIprCorner::setNTarget_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setNTarget_reply >::allocate_sample(DdsJobWzskIprCorner::setNTarget_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setRoi_reqPlugin_new,
                DdsJobWzskIprCorner::setRoi_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setRoi_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setRoi_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoi_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoi_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_req >::from_cdr_buffer(DdsJobWzskIprCorner::setRoi_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoi_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setRoi_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_req >::reset_sample(DdsJobWzskIprCorner::setRoi_req& sample) 
        {
            sample.roiAx(0);
            sample.roiAy(0);
            sample.roiBx(0);
            sample.roiBy(0);
            sample.roiCx(0);
            sample.roiCy(0);
            sample.roiDx(0);
            sample.roiDy(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_req >::allocate_sample(DdsJobWzskIprCorner::setRoi_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setRoi_replyPlugin_new,
                DdsJobWzskIprCorner::setRoi_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setRoi_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setRoi_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoi_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoi_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_reply >::from_cdr_buffer(DdsJobWzskIprCorner::setRoi_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoi_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setRoi_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_reply >::reset_sample(DdsJobWzskIprCorner::setRoi_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoi_reply >::allocate_sample(DdsJobWzskIprCorner::setRoi_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setRoiNotFull_reqPlugin_new,
                DdsJobWzskIprCorner::setRoiNotFull_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setRoiNotFull_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req >::from_cdr_buffer(DdsJobWzskIprCorner::setRoiNotFull_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoiNotFull_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setRoiNotFull_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req >::reset_sample(DdsJobWzskIprCorner::setRoiNotFull_req& sample) 
        {
            sample.roiNotFull(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_req >::allocate_sample(DdsJobWzskIprCorner::setRoiNotFull_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::setRoiNotFull_replyPlugin_new,
                DdsJobWzskIprCorner::setRoiNotFull_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::setRoiNotFull_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply >::from_cdr_buffer(DdsJobWzskIprCorner::setRoiNotFull_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRoiNotFull_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::setRoiNotFull_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply >::reset_sample(DdsJobWzskIprCorner::setRoiNotFull_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::setRoiNotFull_reply >::allocate_sample(DdsJobWzskIprCorner::setRoiNotFull_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::NTarget >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::NTargetPlugin_new,
                DdsJobWzskIprCorner::NTargetPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::NTarget >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::NTarget& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = NTargetPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = NTargetPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::NTarget >::from_cdr_buffer(DdsJobWzskIprCorner::NTarget& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = NTargetPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::NTarget from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::NTarget >::reset_sample(DdsJobWzskIprCorner::NTarget& sample) 
        {
            sample._NTarget(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::NTarget >::allocate_sample(DdsJobWzskIprCorner::NTarget& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_new,
                DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::from_cdr_buffer(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::reset_sample(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample) 
        {
            sample.roiAx(0);
            sample.roiAy(0);
            sample.roiBx(0);
            sample.roiBy(0);
            sample.roiCx(0);
            sample.roiCy(0);
            sample.roiDx(0);
            sample.roiDy(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy >::allocate_sample(DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskIprCorner::flgShiftScoreMinScoreMaxPlugin_new,
                DdsJobWzskIprCorner::flgShiftScoreMinScoreMaxPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskIprCorner::flgShiftScoreMinScoreMax& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = flgShiftScoreMinScoreMaxPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = flgShiftScoreMinScoreMaxPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::from_cdr_buffer(DdsJobWzskIprCorner::flgShiftScoreMinScoreMax& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = flgShiftScoreMinScoreMaxPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskIprCorner::flgShiftScoreMinScoreMax from cdr buffer");
        }

        void topic_type_support< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::reset_sample(DdsJobWzskIprCorner::flgShiftScoreMinScoreMax& sample) 
        {
            ::rti::topic::reset_sample(sample.flg());
            sample.shift(0);
            sample.scoreMin(0);
            sample.scoreMax(0);
        }

        void topic_type_support< DdsJobWzskIprCorner::flgShiftScoreMinScoreMax >::allocate_sample(DdsJobWzskIprCorner::flgShiftScoreMinScoreMax& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.flg(),  786432, -1);
        }

        void topic_type_support< DdsJobWzskActServo::moveto_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::moveto_reqPlugin_new,
                DdsJobWzskActServo::moveto_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::moveto_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::moveto_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = moveto_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = moveto_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::moveto_req >::from_cdr_buffer(DdsJobWzskActServo::moveto_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = moveto_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::moveto_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::moveto_req >::reset_sample(DdsJobWzskActServo::moveto_req& sample) 
        {
            sample.target(0.0f);
        }

        void topic_type_support< DdsJobWzskActServo::moveto_req >::allocate_sample(DdsJobWzskActServo::moveto_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::moveto_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::moveto_replyPlugin_new,
                DdsJobWzskActServo::moveto_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::moveto_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::moveto_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = moveto_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = moveto_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::moveto_reply >::from_cdr_buffer(DdsJobWzskActServo::moveto_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = moveto_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::moveto_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::moveto_reply >::reset_sample(DdsJobWzskActServo::moveto_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActServo::moveto_reply >::allocate_sample(DdsJobWzskActServo::moveto_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::stop_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::stop_reqPlugin_new,
                DdsJobWzskActServo::stop_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::stop_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::stop_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::stop_req >::from_cdr_buffer(DdsJobWzskActServo::stop_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::stop_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::stop_req >::reset_sample(DdsJobWzskActServo::stop_req& sample) 
        {
            sample.dummy(0);
        }

        void topic_type_support< DdsJobWzskActServo::stop_req >::allocate_sample(DdsJobWzskActServo::stop_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::stop_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::stop_replyPlugin_new,
                DdsJobWzskActServo::stop_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::stop_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::stop_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = stop_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = stop_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::stop_reply >::from_cdr_buffer(DdsJobWzskActServo::stop_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = stop_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::stop_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::stop_reply >::reset_sample(DdsJobWzskActServo::stop_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActServo::stop_reply >::allocate_sample(DdsJobWzskActServo::stop_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::turn_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::turn_reqPlugin_new,
                DdsJobWzskActServo::turn_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::turn_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::turn_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = turn_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = turn_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::turn_req >::from_cdr_buffer(DdsJobWzskActServo::turn_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = turn_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::turn_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::turn_req >::reset_sample(DdsJobWzskActServo::turn_req& sample) 
        {
            sample.ccwNotCw(0);
        }

        void topic_type_support< DdsJobWzskActServo::turn_req >::allocate_sample(DdsJobWzskActServo::turn_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::turn_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::turn_replyPlugin_new,
                DdsJobWzskActServo::turn_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::turn_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::turn_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = turn_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = turn_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::turn_reply >::from_cdr_buffer(DdsJobWzskActServo::turn_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = turn_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::turn_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::turn_reply >::reset_sample(DdsJobWzskActServo::turn_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActServo::turn_reply >::allocate_sample(DdsJobWzskActServo::turn_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::zero_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::zero_reqPlugin_new,
                DdsJobWzskActServo::zero_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::zero_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::zero_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = zero_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = zero_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::zero_req >::from_cdr_buffer(DdsJobWzskActServo::zero_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = zero_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::zero_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::zero_req >::reset_sample(DdsJobWzskActServo::zero_req& sample) 
        {
            sample.dummy(0);
        }

        void topic_type_support< DdsJobWzskActServo::zero_req >::allocate_sample(DdsJobWzskActServo::zero_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::zero_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::zero_replyPlugin_new,
                DdsJobWzskActServo::zero_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::zero_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::zero_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = zero_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = zero_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::zero_reply >::from_cdr_buffer(DdsJobWzskActServo::zero_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = zero_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::zero_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::zero_reply >::reset_sample(DdsJobWzskActServo::zero_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActServo::zero_reply >::allocate_sample(DdsJobWzskActServo::zero_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActServo::angleTarget >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActServo::angleTargetPlugin_new,
                DdsJobWzskActServo::angleTargetPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActServo::angleTarget >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActServo::angleTarget& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = angleTargetPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = angleTargetPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActServo::angleTarget >::from_cdr_buffer(DdsJobWzskActServo::angleTarget& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = angleTargetPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActServo::angleTarget from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActServo::angleTarget >::reset_sample(DdsJobWzskActServo::angleTarget& sample) 
        {
            sample.angle(0.0f);
            sample.target(0.0f);
        }

        void topic_type_support< DdsJobWzskActServo::angleTarget >::allocate_sample(DdsJobWzskActServo::angleTarget& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActLaser::setLeft_reqPlugin_new,
                DdsJobWzskActLaser::setLeft_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActLaser::setLeft_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActLaser::setLeft_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setLeft_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setLeft_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_req >::from_cdr_buffer(DdsJobWzskActLaser::setLeft_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setLeft_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActLaser::setLeft_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_req >::reset_sample(DdsJobWzskActLaser::setLeft_req& sample) 
        {
            sample.left(0.0f);
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_req >::allocate_sample(DdsJobWzskActLaser::setLeft_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActLaser::setLeft_replyPlugin_new,
                DdsJobWzskActLaser::setLeft_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActLaser::setLeft_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActLaser::setLeft_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setLeft_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setLeft_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_reply >::from_cdr_buffer(DdsJobWzskActLaser::setLeft_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setLeft_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActLaser::setLeft_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_reply >::reset_sample(DdsJobWzskActLaser::setLeft_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActLaser::setLeft_reply >::allocate_sample(DdsJobWzskActLaser::setLeft_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActLaser::setRight_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActLaser::setRight_reqPlugin_new,
                DdsJobWzskActLaser::setRight_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActLaser::setRight_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActLaser::setRight_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRight_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRight_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_req >::from_cdr_buffer(DdsJobWzskActLaser::setRight_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRight_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActLaser::setRight_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_req >::reset_sample(DdsJobWzskActLaser::setRight_req& sample) 
        {
            sample.right(0.0f);
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_req >::allocate_sample(DdsJobWzskActLaser::setRight_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActLaser::setRight_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActLaser::setRight_replyPlugin_new,
                DdsJobWzskActLaser::setRight_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActLaser::setRight_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActLaser::setRight_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setRight_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setRight_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_reply >::from_cdr_buffer(DdsJobWzskActLaser::setRight_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setRight_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActLaser::setRight_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_reply >::reset_sample(DdsJobWzskActLaser::setRight_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActLaser::setRight_reply >::allocate_sample(DdsJobWzskActLaser::setRight_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActLaser::leftRight >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActLaser::leftRightPlugin_new,
                DdsJobWzskActLaser::leftRightPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActLaser::leftRight >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActLaser::leftRight& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = leftRightPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = leftRightPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActLaser::leftRight >::from_cdr_buffer(DdsJobWzskActLaser::leftRight& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = leftRightPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActLaser::leftRight from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActLaser::leftRight >::reset_sample(DdsJobWzskActLaser::leftRight& sample) 
        {
            sample.left(0.0f);
            sample.right(0.0f);
        }

        void topic_type_support< DdsJobWzskActLaser::leftRight >::allocate_sample(DdsJobWzskActLaser::leftRight& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::setExposure_reqPlugin_new,
                DdsJobWzskActExposure::setExposure_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::setExposure_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::setExposure_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setExposure_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setExposure_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_req >::from_cdr_buffer(DdsJobWzskActExposure::setExposure_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setExposure_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::setExposure_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_req >::reset_sample(DdsJobWzskActExposure::setExposure_req& sample) 
        {
            sample.autoNotManual(0);
            sample.Texp(0.0f);
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_req >::allocate_sample(DdsJobWzskActExposure::setExposure_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::setExposure_replyPlugin_new,
                DdsJobWzskActExposure::setExposure_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::setExposure_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::setExposure_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setExposure_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setExposure_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_reply >::from_cdr_buffer(DdsJobWzskActExposure::setExposure_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setExposure_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::setExposure_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_reply >::reset_sample(DdsJobWzskActExposure::setExposure_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActExposure::setExposure_reply >::allocate_sample(DdsJobWzskActExposure::setExposure_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::setFocus_reqPlugin_new,
                DdsJobWzskActExposure::setFocus_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::setFocus_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::setFocus_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_req >::from_cdr_buffer(DdsJobWzskActExposure::setFocus_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::setFocus_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_req >::reset_sample(DdsJobWzskActExposure::setFocus_req& sample) 
        {
            sample.focus(0.0f);
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_req >::allocate_sample(DdsJobWzskActExposure::setFocus_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::setFocus_replyPlugin_new,
                DdsJobWzskActExposure::setFocus_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::setFocus_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::setFocus_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setFocus_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_reply >::from_cdr_buffer(DdsJobWzskActExposure::setFocus_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setFocus_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::setFocus_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_reply >::reset_sample(DdsJobWzskActExposure::setFocus_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskActExposure::setFocus_reply >::allocate_sample(DdsJobWzskActExposure::setFocus_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::autoNotManualTexp >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::autoNotManualTexpPlugin_new,
                DdsJobWzskActExposure::autoNotManualTexpPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::autoNotManualTexp >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::autoNotManualTexp& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = autoNotManualTexpPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = autoNotManualTexpPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::autoNotManualTexp >::from_cdr_buffer(DdsJobWzskActExposure::autoNotManualTexp& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = autoNotManualTexpPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::autoNotManualTexp from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::autoNotManualTexp >::reset_sample(DdsJobWzskActExposure::autoNotManualTexp& sample) 
        {
            sample.autoNotManual(0);
            sample.Texp(0.0f);
        }

        void topic_type_support< DdsJobWzskActExposure::autoNotManualTexp >::allocate_sample(DdsJobWzskActExposure::autoNotManualTexp& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskActExposure::focus >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskActExposure::focusPlugin_new,
                DdsJobWzskActExposure::focusPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskActExposure::focus >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskActExposure::focus& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = focusPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = focusPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskActExposure::focus >::from_cdr_buffer(DdsJobWzskActExposure::focus& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = focusPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskActExposure::focus from cdr buffer");
        }

        void topic_type_support< DdsJobWzskActExposure::focus >::reset_sample(DdsJobWzskActExposure::focus& sample) 
        {
            sample._focus(0.0f);
        }

        void topic_type_support< DdsJobWzskActExposure::focus >::allocate_sample(DdsJobWzskActExposure::focus& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPtcloud::setDeltaTheta_reqPlugin_new,
                DdsJobWzskAcqPtcloud::setDeltaTheta_reqPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setDeltaTheta_reqPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setDeltaTheta_reqPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::from_cdr_buffer(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setDeltaTheta_reqPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPtcloud::setDeltaTheta_req from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::reset_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample) 
        {
            sample.deltaTheta(0.0f);
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_req >::allocate_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_req& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPtcloud::setDeltaTheta_replyPlugin_new,
                DdsJobWzskAcqPtcloud::setDeltaTheta_replyPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = setDeltaTheta_replyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = setDeltaTheta_replyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::from_cdr_buffer(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = setDeltaTheta_replyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPtcloud::setDeltaTheta_reply from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::reset_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample) 
        {
            sample.success(0);
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::setDeltaTheta_reply >::allocate_sample(DdsJobWzskAcqPtcloud::setDeltaTheta_reply& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPtcloud::deltaThetaPlugin_new,
                DdsJobWzskAcqPtcloud::deltaThetaPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPtcloud::deltaTheta& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = deltaThetaPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = deltaThetaPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta >::from_cdr_buffer(DdsJobWzskAcqPtcloud::deltaTheta& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = deltaThetaPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPtcloud::deltaTheta from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta >::reset_sample(DdsJobWzskAcqPtcloud::deltaTheta& sample) 
        {
            sample._deltaTheta(0.0f);
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::deltaTheta >::allocate_sample(DdsJobWzskAcqPtcloud::deltaTheta& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

        }

        void topic_type_support< DdsJobWzskAcqPtcloud::xYZ >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPtcloud::xYZPlugin_new,
                DdsJobWzskAcqPtcloud::xYZPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPtcloud::xYZ >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPtcloud::xYZ& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = xYZPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = xYZPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::xYZ >::from_cdr_buffer(DdsJobWzskAcqPtcloud::xYZ& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = xYZPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPtcloud::xYZ from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::xYZ >::reset_sample(DdsJobWzskAcqPtcloud::xYZ& sample) 
        {
            ::rti::topic::reset_sample(sample.x());
            ::rti::topic::reset_sample(sample.y());
            ::rti::topic::reset_sample(sample.z());
        }

        void topic_type_support< DdsJobWzskAcqPtcloud::xYZ >::allocate_sample(DdsJobWzskAcqPtcloud::xYZ& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.x(),  72000, -1);
            ::rti::topic::allocate_sample(sample.y(),  72000, -1);
            ::rti::topic::allocate_sample(sample.z(),  72000, -1);
        }

        void topic_type_support< DdsJobWzskAcqPreview::gray >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPreview::grayPlugin_new,
                DdsJobWzskAcqPreview::grayPlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPreview::gray >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPreview::gray& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = grayPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = grayPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPreview::gray >::from_cdr_buffer(DdsJobWzskAcqPreview::gray& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = grayPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPreview::gray from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPreview::gray >::reset_sample(DdsJobWzskAcqPreview::gray& sample) 
        {
            ::rti::topic::reset_sample(sample._gray());
        }

        void topic_type_support< DdsJobWzskAcqPreview::gray >::allocate_sample(DdsJobWzskAcqPreview::gray& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample._gray(),  49152, -1);
        }

        void topic_type_support< DdsJobWzskAcqPreview::redGreenBlue >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DdsJobWzskAcqPreview::redGreenBluePlugin_new,
                DdsJobWzskAcqPreview::redGreenBluePlugin_delete);
        }

        std::vector<char>& topic_type_support< DdsJobWzskAcqPreview::redGreenBlue >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DdsJobWzskAcqPreview::redGreenBlue& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = redGreenBluePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = redGreenBluePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DdsJobWzskAcqPreview::redGreenBlue >::from_cdr_buffer(DdsJobWzskAcqPreview::redGreenBlue& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = redGreenBluePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DdsJobWzskAcqPreview::redGreenBlue from cdr buffer");
        }

        void topic_type_support< DdsJobWzskAcqPreview::redGreenBlue >::reset_sample(DdsJobWzskAcqPreview::redGreenBlue& sample) 
        {
            ::rti::topic::reset_sample(sample.red());
            ::rti::topic::reset_sample(sample.green());
            ::rti::topic::reset_sample(sample.blue());
        }

        void topic_type_support< DdsJobWzskAcqPreview::redGreenBlue >::allocate_sample(DdsJobWzskAcqPreview::redGreenBlue& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample); // [[maybe_unused]]

            ::rti::topic::allocate_sample(sample.red(),  19200, -1);
            ::rti::topic::allocate_sample(sample.green(),  19200, -1);
            ::rti::topic::allocate_sample(sample.blue(),  19200, -1);
        }

    }
}  

