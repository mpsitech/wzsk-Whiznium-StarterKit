

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DdsWzsk.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef DdsWzskPlugin_509372353_h
#define DdsWzskPlugin_509372353_h

#include "DdsWzsk.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define tinyintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define tinyintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tinyintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define tinyintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tinyintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tinyint*
tinyintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tinyintPluginSupport_copy_data(
    tinyint *out,
    const tinyint *in);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data_w_params(
    tinyint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data_ex(
    tinyint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tinyintPluginSupport_destroy_data(
    tinyint *sample);

NDDSUSERDllExport extern void 
tinyintPluginSupport_print_data(
    const tinyint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tinyintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tinyint *out,
    const tinyint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
tinyintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tinyintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define utinyintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define utinyintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define utinyintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define utinyintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define utinyintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern utinyint*
utinyintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
utinyintPluginSupport_copy_data(
    utinyint *out,
    const utinyint *in);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data_w_params(
    utinyint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data_ex(
    utinyint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
utinyintPluginSupport_destroy_data(
    utinyint *sample);

NDDSUSERDllExport extern void 
utinyintPluginSupport_print_data(
    const utinyint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
utinyintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    utinyint *out,
    const utinyint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
utinyintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
utinyintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define smallintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define smallintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define smallintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define smallintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define smallintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern smallint*
smallintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
smallintPluginSupport_copy_data(
    smallint *out,
    const smallint *in);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data_w_params(
    smallint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data_ex(
    smallint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
smallintPluginSupport_destroy_data(
    smallint *sample);

NDDSUSERDllExport extern void 
smallintPluginSupport_print_data(
    const smallint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
smallintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    smallint *out,
    const smallint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
smallintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
smallintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define usmallintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define usmallintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define usmallintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define usmallintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define usmallintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern usmallint*
usmallintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
usmallintPluginSupport_copy_data(
    usmallint *out,
    const usmallint *in);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data_w_params(
    usmallint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data_ex(
    usmallint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
usmallintPluginSupport_destroy_data(
    usmallint *sample);

NDDSUSERDllExport extern void 
usmallintPluginSupport_print_data(
    const usmallint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
usmallintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    usmallint *out,
    const usmallint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
usmallintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
usmallintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define _cxx_intPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define _cxx_intPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define _cxx_intPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define _cxx_intPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define _cxx_intPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern _cxx_int*
_cxx_intPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
_cxx_intPluginSupport_copy_data(
    _cxx_int *out,
    const _cxx_int *in);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data_w_params(
    _cxx_int *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data_ex(
    _cxx_int *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_destroy_data(
    _cxx_int *sample);

NDDSUSERDllExport extern void 
_cxx_intPluginSupport_print_data(
    const _cxx_int *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
_cxx_intPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    _cxx_int *out,
    const _cxx_int *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
_cxx_intPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
_cxx_intPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define uintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define uintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define uintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define uintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define uintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern uint*
uintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
uintPluginSupport_copy_data(
    uint *out,
    const uint *in);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data_w_params(
    uint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data_ex(
    uint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
uintPluginSupport_destroy_data(
    uint *sample);

NDDSUSERDllExport extern void 
uintPluginSupport_print_data(
    const uint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
uintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    uint *out,
    const uint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
uintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
uintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define bigintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define bigintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define bigintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define bigintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define bigintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern bigint*
bigintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
bigintPluginSupport_copy_data(
    bigint *out,
    const bigint *in);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data_w_params(
    bigint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data_ex(
    bigint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
bigintPluginSupport_destroy_data(
    bigint *sample);

NDDSUSERDllExport extern void 
bigintPluginSupport_print_data(
    const bigint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
bigintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    bigint *out,
    const bigint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
bigintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
bigintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define ubigintPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ubigintPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ubigintPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ubigintPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ubigintPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ubigint*
ubigintPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ubigintPluginSupport_copy_data(
    ubigint *out,
    const ubigint *in);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data_w_params(
    ubigint *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data_ex(
    ubigint *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ubigintPluginSupport_destroy_data(
    ubigint *sample);

NDDSUSERDllExport extern void 
ubigintPluginSupport_print_data(
    const ubigint *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ubigintPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ubigint *out,
    const ubigint *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ubigintPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ubigintPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define DdsFloatmatPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DdsFloatmatPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DdsFloatmatPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DdsFloatmatPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DdsFloatmatPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DdsFloatmat*
DdsFloatmatPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPluginSupport_copy_data(
    DdsFloatmat *out,
    const DdsFloatmat *in);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data_w_params(
    DdsFloatmat *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data_ex(
    DdsFloatmat *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_destroy_data(
    DdsFloatmat *sample);

NDDSUSERDllExport extern void 
DdsFloatmatPluginSupport_print_data(
    const DdsFloatmat *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DdsFloatmatPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DdsFloatmatPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DdsFloatmatPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DdsFloatmatPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DdsFloatmatPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat *out,
    const DdsFloatmat *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DdsFloatmat *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsFloatmatPlugin_deserialize_from_cdr_buffer(
    DdsFloatmat *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DdsFloatmatPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsFloatmatPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DdsFloatmatPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsFloatmat ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DdsFloatmatPlugin_new(void);

NDDSUSERDllExport extern void
DdsFloatmatPlugin_delete(struct PRESTypePlugin *);

#define DdsDoublematPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DdsDoublematPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DdsDoublematPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DdsDoublematPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DdsDoublematPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DdsDoublemat*
DdsDoublematPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPluginSupport_copy_data(
    DdsDoublemat *out,
    const DdsDoublemat *in);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data_w_params(
    DdsDoublemat *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data_ex(
    DdsDoublemat *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_destroy_data(
    DdsDoublemat *sample);

NDDSUSERDllExport extern void 
DdsDoublematPluginSupport_print_data(
    const DdsDoublemat *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DdsDoublematPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DdsDoublematPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DdsDoublematPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DdsDoublematPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DdsDoublematPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat *out,
    const DdsDoublemat *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DdsDoublemat *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DdsDoublematPlugin_deserialize_from_cdr_buffer(
    DdsDoublemat *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DdsDoublematPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DdsDoublematPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DdsDoublematPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DdsDoublemat ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DdsDoublematPlugin_new(void);

NDDSUSERDllExport extern void
DdsDoublematPlugin_delete(struct PRESTypePlugin *);

#define stringvecPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define stringvecPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define stringvecPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define stringvecPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define stringvecPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern stringvec*
stringvecPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
stringvecPluginSupport_copy_data(
    stringvec *out,
    const stringvec *in);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data_w_params(
    stringvec *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data_ex(
    stringvec *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
stringvecPluginSupport_destroy_data(
    stringvec *sample);

NDDSUSERDllExport extern void 
stringvecPluginSupport_print_data(
    const stringvec *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
stringvecPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    stringvec *out,
    const stringvec *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
stringvecPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
stringvecPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

#define vecsrefPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define vecsrefPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define vecsrefPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define vecsrefPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define vecsrefPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern vecsref*
vecsrefPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
vecsrefPluginSupport_copy_data(
    vecsref *out,
    const vecsref *in);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data_w_params(
    vecsref *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data_ex(
    vecsref *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_destroy_data(
    vecsref *sample);

NDDSUSERDllExport extern void 
vecsrefPluginSupport_print_data(
    const vecsref *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
vecsrefPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    vecsref *out,
    const vecsref *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
vecsrefPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
vecsrefPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

namespace DdsJobWzskSrcSysinfo {

    #define loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern loadAllLoadCore0LoadCore1LoadCore2LoadCore3*
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern loadAllLoadCore0LoadCore1LoadCore2LoadCore3*
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern loadAllLoadCore0LoadCore1LoadCore2LoadCore3*
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_copy_data(
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *out,
        const loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *in);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_destroy_data_w_params(
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_destroy_data_ex(
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_destroy_data(
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3PluginSupport_print_data(
        const loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *out,
        const loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_deserialize_from_cdr_buffer(
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        loadAllLoadCore0LoadCore1LoadCore2LoadCore3 ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_new(void);

    NDDSUSERDllExport extern void
    loadAllLoadCore0LoadCore1LoadCore2LoadCore3Plugin_delete(struct PRESTypePlugin *);

    #define tempPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define tempPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define tempPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define tempPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define tempPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern temp*
    tempPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern temp*
    tempPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern temp*
    tempPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    tempPluginSupport_copy_data(
        temp *out,
        const temp *in);

    NDDSUSERDllExport extern void 
    tempPluginSupport_destroy_data_w_params(
        temp *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    tempPluginSupport_destroy_data_ex(
        temp *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    tempPluginSupport_destroy_data(
        temp *sample);

    NDDSUSERDllExport extern void 
    tempPluginSupport_print_data(
        const temp *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    tempPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    tempPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    tempPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    tempPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    tempPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        temp *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    tempPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        temp *out,
        const temp *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    tempPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const temp *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    tempPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        temp **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    tempPlugin_deserialize_from_cdr_buffer(
        temp *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    tempPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    tempPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    tempPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    tempPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    tempPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        temp ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    tempPlugin_new(void);

    NDDSUSERDllExport extern void
    tempPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskSrcSysinfo  */
namespace DdsJobWzskIprTrace {

    #define setLevel_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setLevel_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setLevel_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setLevel_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setLevel_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setLevel_req*
    setLevel_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setLevel_req*
    setLevel_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setLevel_req*
    setLevel_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setLevel_reqPluginSupport_copy_data(
        setLevel_req *out,
        const setLevel_req *in);

    NDDSUSERDllExport extern void 
    setLevel_reqPluginSupport_destroy_data_w_params(
        setLevel_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setLevel_reqPluginSupport_destroy_data_ex(
        setLevel_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setLevel_reqPluginSupport_destroy_data(
        setLevel_req *sample);

    NDDSUSERDllExport extern void 
    setLevel_reqPluginSupport_print_data(
        const setLevel_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setLevel_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setLevel_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setLevel_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setLevel_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setLevel_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setLevel_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_req *out,
        const setLevel_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setLevel_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setLevel_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setLevel_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setLevel_reqPlugin_deserialize_from_cdr_buffer(
        setLevel_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setLevel_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setLevel_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setLevel_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setLevel_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setLevel_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setLevel_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setLevel_reqPlugin_delete(struct PRESTypePlugin *);

    #define setLevel_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setLevel_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setLevel_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setLevel_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setLevel_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setLevel_reply*
    setLevel_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setLevel_reply*
    setLevel_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setLevel_reply*
    setLevel_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setLevel_replyPluginSupport_copy_data(
        setLevel_reply *out,
        const setLevel_reply *in);

    NDDSUSERDllExport extern void 
    setLevel_replyPluginSupport_destroy_data_w_params(
        setLevel_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setLevel_replyPluginSupport_destroy_data_ex(
        setLevel_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setLevel_replyPluginSupport_destroy_data(
        setLevel_reply *sample);

    NDDSUSERDllExport extern void 
    setLevel_replyPluginSupport_print_data(
        const setLevel_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setLevel_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setLevel_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setLevel_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setLevel_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setLevel_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setLevel_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_reply *out,
        const setLevel_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setLevel_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setLevel_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setLevel_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setLevel_replyPlugin_deserialize_from_cdr_buffer(
        setLevel_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setLevel_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setLevel_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setLevel_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setLevel_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setLevel_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setLevel_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setLevel_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setLevel_replyPlugin_delete(struct PRESTypePlugin *);

    #define setRoi_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoi_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoi_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoi_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoi_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPluginSupport_copy_data(
        setRoi_req *out,
        const setRoi_req *in);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data_w_params(
        setRoi_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data_ex(
        setRoi_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data(
        setRoi_req *sample);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_print_data(
        const setRoi_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoi_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoi_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoi_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoi_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoi_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req *out,
        const setRoi_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoi_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoi_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoi_reqPlugin_deserialize_from_cdr_buffer(
        setRoi_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoi_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoi_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoi_reqPlugin_delete(struct PRESTypePlugin *);

    #define setRoi_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoi_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoi_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoi_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoi_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPluginSupport_copy_data(
        setRoi_reply *out,
        const setRoi_reply *in);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data_w_params(
        setRoi_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data_ex(
        setRoi_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data(
        setRoi_reply *sample);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_print_data(
        const setRoi_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoi_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoi_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoi_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoi_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoi_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply *out,
        const setRoi_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoi_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoi_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoi_replyPlugin_deserialize_from_cdr_buffer(
        setRoi_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoi_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoi_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoi_replyPlugin_delete(struct PRESTypePlugin *);

    #define setRoiNotFull_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoiNotFull_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoiNotFull_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoiNotFull_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoiNotFull_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPluginSupport_copy_data(
        setRoiNotFull_req *out,
        const setRoiNotFull_req *in);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data_w_params(
        setRoiNotFull_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data_ex(
        setRoiNotFull_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data(
        setRoiNotFull_req *sample);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_print_data(
        const setRoiNotFull_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoiNotFull_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoiNotFull_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoiNotFull_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req *out,
        const setRoiNotFull_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoiNotFull_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_reqPlugin_deserialize_from_cdr_buffer(
        setRoiNotFull_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoiNotFull_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoiNotFull_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoiNotFull_reqPlugin_delete(struct PRESTypePlugin *);

    #define setRoiNotFull_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoiNotFull_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoiNotFull_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoiNotFull_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoiNotFull_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPluginSupport_copy_data(
        setRoiNotFull_reply *out,
        const setRoiNotFull_reply *in);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data_w_params(
        setRoiNotFull_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data_ex(
        setRoiNotFull_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data(
        setRoiNotFull_reply *sample);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_print_data(
        const setRoiNotFull_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoiNotFull_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoiNotFull_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoiNotFull_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply *out,
        const setRoiNotFull_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoiNotFull_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_replyPlugin_deserialize_from_cdr_buffer(
        setRoiNotFull_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoiNotFull_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoiNotFull_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoiNotFull_replyPlugin_delete(struct PRESTypePlugin *);

    #define pOnLeftPOnRightPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define pOnLeftPOnRightPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define pOnLeftPOnRightPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define pOnLeftPOnRightPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define pOnLeftPOnRightPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern pOnLeftPOnRight*
    pOnLeftPOnRightPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern pOnLeftPOnRight*
    pOnLeftPOnRightPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern pOnLeftPOnRight*
    pOnLeftPOnRightPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    pOnLeftPOnRightPluginSupport_copy_data(
        pOnLeftPOnRight *out,
        const pOnLeftPOnRight *in);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPluginSupport_destroy_data_w_params(
        pOnLeftPOnRight *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPluginSupport_destroy_data_ex(
        pOnLeftPOnRight *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPluginSupport_destroy_data(
        pOnLeftPOnRight *sample);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPluginSupport_print_data(
        const pOnLeftPOnRight *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    pOnLeftPOnRightPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    pOnLeftPOnRightPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    pOnLeftPOnRightPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    pOnLeftPOnRightPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        pOnLeftPOnRight *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    pOnLeftPOnRightPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        pOnLeftPOnRight *out,
        const pOnLeftPOnRight *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    pOnLeftPOnRightPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const pOnLeftPOnRight *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    pOnLeftPOnRightPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        pOnLeftPOnRight **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    pOnLeftPOnRightPlugin_deserialize_from_cdr_buffer(
        pOnLeftPOnRight *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    pOnLeftPOnRightPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    pOnLeftPOnRightPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    pOnLeftPOnRightPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    pOnLeftPOnRightPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    pOnLeftPOnRightPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        pOnLeftPOnRight ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    pOnLeftPOnRightPlugin_new(void);

    NDDSUSERDllExport extern void
    pOnLeftPOnRightPlugin_delete(struct PRESTypePlugin *);

    #define levelOnLevelOffPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define levelOnLevelOffPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define levelOnLevelOffPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define levelOnLevelOffPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define levelOnLevelOffPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern levelOnLevelOff*
    levelOnLevelOffPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern levelOnLevelOff*
    levelOnLevelOffPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern levelOnLevelOff*
    levelOnLevelOffPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    levelOnLevelOffPluginSupport_copy_data(
        levelOnLevelOff *out,
        const levelOnLevelOff *in);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPluginSupport_destroy_data_w_params(
        levelOnLevelOff *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPluginSupport_destroy_data_ex(
        levelOnLevelOff *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPluginSupport_destroy_data(
        levelOnLevelOff *sample);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPluginSupport_print_data(
        const levelOnLevelOff *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    levelOnLevelOffPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    levelOnLevelOffPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    levelOnLevelOffPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    levelOnLevelOffPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        levelOnLevelOff *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    levelOnLevelOffPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        levelOnLevelOff *out,
        const levelOnLevelOff *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    levelOnLevelOffPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const levelOnLevelOff *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    levelOnLevelOffPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        levelOnLevelOff **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    levelOnLevelOffPlugin_deserialize_from_cdr_buffer(
        levelOnLevelOff *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    levelOnLevelOffPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    levelOnLevelOffPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    levelOnLevelOffPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    levelOnLevelOffPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    levelOnLevelOffPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        levelOnLevelOff ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    levelOnLevelOffPlugin_new(void);

    NDDSUSERDllExport extern void
    levelOnLevelOffPlugin_delete(struct PRESTypePlugin *);

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_copy_data(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *out,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *in);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data_w_params(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data_ex(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_print_data(
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *out,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_from_cdr_buffer(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_new(void);

    NDDSUSERDllExport extern void
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_delete(struct PRESTypePlugin *);

    #define leftRightPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define leftRightPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define leftRightPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define leftRightPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define leftRightPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    leftRightPluginSupport_copy_data(
        leftRight *out,
        const leftRight *in);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data_w_params(
        leftRight *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data_ex(
        leftRight *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data(
        leftRight *sample);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_print_data(
        const leftRight *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    leftRightPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    leftRightPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    leftRightPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    leftRightPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    leftRightPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        leftRight *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        leftRight *out,
        const leftRight *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    leftRightPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const leftRight *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        leftRight **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    leftRightPlugin_deserialize_from_cdr_buffer(
        leftRight *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    leftRightPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        leftRight ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    leftRightPlugin_new(void);

    NDDSUSERDllExport extern void
    leftRightPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskIprTrace  */
namespace DdsJobWzskIprCorner {

    #define setNTarget_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setNTarget_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setNTarget_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setNTarget_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setNTarget_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setNTarget_req*
    setNTarget_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setNTarget_req*
    setNTarget_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setNTarget_req*
    setNTarget_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setNTarget_reqPluginSupport_copy_data(
        setNTarget_req *out,
        const setNTarget_req *in);

    NDDSUSERDllExport extern void 
    setNTarget_reqPluginSupport_destroy_data_w_params(
        setNTarget_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setNTarget_reqPluginSupport_destroy_data_ex(
        setNTarget_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setNTarget_reqPluginSupport_destroy_data(
        setNTarget_req *sample);

    NDDSUSERDllExport extern void 
    setNTarget_reqPluginSupport_print_data(
        const setNTarget_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setNTarget_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setNTarget_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setNTarget_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setNTarget_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setNTarget_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setNTarget_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_req *out,
        const setNTarget_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setNTarget_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setNTarget_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setNTarget_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setNTarget_reqPlugin_deserialize_from_cdr_buffer(
        setNTarget_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setNTarget_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setNTarget_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setNTarget_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setNTarget_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setNTarget_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setNTarget_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setNTarget_reqPlugin_delete(struct PRESTypePlugin *);

    #define setNTarget_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setNTarget_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setNTarget_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setNTarget_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setNTarget_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setNTarget_reply*
    setNTarget_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setNTarget_reply*
    setNTarget_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setNTarget_reply*
    setNTarget_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setNTarget_replyPluginSupport_copy_data(
        setNTarget_reply *out,
        const setNTarget_reply *in);

    NDDSUSERDllExport extern void 
    setNTarget_replyPluginSupport_destroy_data_w_params(
        setNTarget_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setNTarget_replyPluginSupport_destroy_data_ex(
        setNTarget_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setNTarget_replyPluginSupport_destroy_data(
        setNTarget_reply *sample);

    NDDSUSERDllExport extern void 
    setNTarget_replyPluginSupport_print_data(
        const setNTarget_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setNTarget_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setNTarget_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setNTarget_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setNTarget_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setNTarget_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setNTarget_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_reply *out,
        const setNTarget_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setNTarget_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setNTarget_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setNTarget_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setNTarget_replyPlugin_deserialize_from_cdr_buffer(
        setNTarget_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setNTarget_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setNTarget_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setNTarget_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setNTarget_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setNTarget_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setNTarget_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setNTarget_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setNTarget_replyPlugin_delete(struct PRESTypePlugin *);

    #define setRoi_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoi_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoi_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoi_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoi_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoi_req*
    setRoi_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPluginSupport_copy_data(
        setRoi_req *out,
        const setRoi_req *in);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data_w_params(
        setRoi_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data_ex(
        setRoi_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_destroy_data(
        setRoi_req *sample);

    NDDSUSERDllExport extern void 
    setRoi_reqPluginSupport_print_data(
        const setRoi_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoi_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoi_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoi_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoi_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoi_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req *out,
        const setRoi_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoi_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoi_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoi_reqPlugin_deserialize_from_cdr_buffer(
        setRoi_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoi_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoi_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoi_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoi_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoi_reqPlugin_delete(struct PRESTypePlugin *);

    #define setRoi_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoi_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoi_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoi_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoi_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoi_reply*
    setRoi_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPluginSupport_copy_data(
        setRoi_reply *out,
        const setRoi_reply *in);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data_w_params(
        setRoi_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data_ex(
        setRoi_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_destroy_data(
        setRoi_reply *sample);

    NDDSUSERDllExport extern void 
    setRoi_replyPluginSupport_print_data(
        const setRoi_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoi_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoi_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoi_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoi_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoi_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply *out,
        const setRoi_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoi_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoi_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoi_replyPlugin_deserialize_from_cdr_buffer(
        setRoi_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoi_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoi_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoi_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoi_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoi_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoi_replyPlugin_delete(struct PRESTypePlugin *);

    #define setRoiNotFull_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoiNotFull_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoiNotFull_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoiNotFull_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoiNotFull_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoiNotFull_req*
    setRoiNotFull_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPluginSupport_copy_data(
        setRoiNotFull_req *out,
        const setRoiNotFull_req *in);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data_w_params(
        setRoiNotFull_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data_ex(
        setRoiNotFull_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_destroy_data(
        setRoiNotFull_req *sample);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPluginSupport_print_data(
        const setRoiNotFull_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoiNotFull_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoiNotFull_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoiNotFull_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoiNotFull_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req *out,
        const setRoiNotFull_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoiNotFull_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_reqPlugin_deserialize_from_cdr_buffer(
        setRoiNotFull_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoiNotFull_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoiNotFull_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoiNotFull_reqPlugin_delete(struct PRESTypePlugin *);

    #define setRoiNotFull_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRoiNotFull_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRoiNotFull_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRoiNotFull_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRoiNotFull_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRoiNotFull_reply*
    setRoiNotFull_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPluginSupport_copy_data(
        setRoiNotFull_reply *out,
        const setRoiNotFull_reply *in);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data_w_params(
        setRoiNotFull_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data_ex(
        setRoiNotFull_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_destroy_data(
        setRoiNotFull_reply *sample);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPluginSupport_print_data(
        const setRoiNotFull_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRoiNotFull_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRoiNotFull_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRoiNotFull_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRoiNotFull_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply *out,
        const setRoiNotFull_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRoiNotFull_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRoiNotFull_replyPlugin_deserialize_from_cdr_buffer(
        setRoiNotFull_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRoiNotFull_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRoiNotFull_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRoiNotFull_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRoiNotFull_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRoiNotFull_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setRoiNotFull_replyPlugin_delete(struct PRESTypePlugin *);

    #define NTargetPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define NTargetPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define NTargetPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define NTargetPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define NTargetPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern NTarget*
    NTargetPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern NTarget*
    NTargetPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern NTarget*
    NTargetPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    NTargetPluginSupport_copy_data(
        NTarget *out,
        const NTarget *in);

    NDDSUSERDllExport extern void 
    NTargetPluginSupport_destroy_data_w_params(
        NTarget *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    NTargetPluginSupport_destroy_data_ex(
        NTarget *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    NTargetPluginSupport_destroy_data(
        NTarget *sample);

    NDDSUSERDllExport extern void 
    NTargetPluginSupport_print_data(
        const NTarget *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    NTargetPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    NTargetPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    NTargetPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    NTargetPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    NTargetPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        NTarget *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    NTargetPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        NTarget *out,
        const NTarget *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    NTargetPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const NTarget *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    NTargetPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        NTarget **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    NTargetPlugin_deserialize_from_cdr_buffer(
        NTarget *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    NTargetPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    NTargetPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    NTargetPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    NTargetPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    NTargetPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        NTarget ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    NTargetPlugin_new(void);

    NDDSUSERDllExport extern void
    NTargetPlugin_delete(struct PRESTypePlugin *);

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_copy_data(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *out,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *in);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data_w_params(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data_ex(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_destroy_data(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPluginSupport_print_data(
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *out,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_from_cdr_buffer(
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_new(void);

    NDDSUSERDllExport extern void
    roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDyPlugin_delete(struct PRESTypePlugin *);

    #define flgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define flgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define flgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define flgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define flgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern flg*
    flgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern flg*
    flgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern flg*
    flgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    flgPluginSupport_copy_data(
        flg *out,
        const flg *in);

    NDDSUSERDllExport extern void 
    flgPluginSupport_destroy_data_w_params(
        flg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    flgPluginSupport_destroy_data_ex(
        flg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    flgPluginSupport_destroy_data(
        flg *sample);

    NDDSUSERDllExport extern void 
    flgPluginSupport_print_data(
        const flg *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    flgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    flgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    flgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    flgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    flgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        flg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    flgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        flg *out,
        const flg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    flgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const flg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    flgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        flg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    flgPlugin_deserialize_from_cdr_buffer(
        flg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    flgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    flgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    flgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    flgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    flgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        flg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    flgPlugin_new(void);

    NDDSUSERDllExport extern void
    flgPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskIprCorner  */
namespace DdsJobWzskActServo {

    #define moveto_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define moveto_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define moveto_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define moveto_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define moveto_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern moveto_req*
    moveto_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern moveto_req*
    moveto_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern moveto_req*
    moveto_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    moveto_reqPluginSupport_copy_data(
        moveto_req *out,
        const moveto_req *in);

    NDDSUSERDllExport extern void 
    moveto_reqPluginSupport_destroy_data_w_params(
        moveto_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    moveto_reqPluginSupport_destroy_data_ex(
        moveto_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    moveto_reqPluginSupport_destroy_data(
        moveto_req *sample);

    NDDSUSERDllExport extern void 
    moveto_reqPluginSupport_print_data(
        const moveto_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    moveto_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    moveto_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    moveto_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    moveto_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    moveto_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        moveto_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    moveto_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        moveto_req *out,
        const moveto_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    moveto_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const moveto_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    moveto_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        moveto_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    moveto_reqPlugin_deserialize_from_cdr_buffer(
        moveto_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    moveto_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    moveto_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    moveto_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    moveto_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    moveto_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        moveto_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    moveto_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    moveto_reqPlugin_delete(struct PRESTypePlugin *);

    #define moveto_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define moveto_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define moveto_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define moveto_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define moveto_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern moveto_reply*
    moveto_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern moveto_reply*
    moveto_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern moveto_reply*
    moveto_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    moveto_replyPluginSupport_copy_data(
        moveto_reply *out,
        const moveto_reply *in);

    NDDSUSERDllExport extern void 
    moveto_replyPluginSupport_destroy_data_w_params(
        moveto_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    moveto_replyPluginSupport_destroy_data_ex(
        moveto_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    moveto_replyPluginSupport_destroy_data(
        moveto_reply *sample);

    NDDSUSERDllExport extern void 
    moveto_replyPluginSupport_print_data(
        const moveto_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    moveto_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    moveto_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    moveto_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    moveto_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    moveto_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        moveto_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    moveto_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        moveto_reply *out,
        const moveto_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    moveto_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const moveto_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    moveto_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        moveto_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    moveto_replyPlugin_deserialize_from_cdr_buffer(
        moveto_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    moveto_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    moveto_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    moveto_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    moveto_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    moveto_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        moveto_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    moveto_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    moveto_replyPlugin_delete(struct PRESTypePlugin *);

    #define stop_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define stop_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define stop_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_req*
    stop_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPluginSupport_copy_data(
        stop_req *out,
        const stop_req *in);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_w_params(
        stop_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data_ex(
        stop_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_destroy_data(
        stop_req *sample);

    NDDSUSERDllExport extern void 
    stop_reqPluginSupport_print_data(
        const stop_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_req *out,
        const stop_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_reqPlugin_deserialize_from_cdr_buffer(
        stop_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_reqPlugin_delete(struct PRESTypePlugin *);

    #define stop_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define stop_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define stop_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define stop_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define stop_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern stop_reply*
    stop_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPluginSupport_copy_data(
        stop_reply *out,
        const stop_reply *in);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_w_params(
        stop_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data_ex(
        stop_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_destroy_data(
        stop_reply *sample);

    NDDSUSERDllExport extern void 
    stop_replyPluginSupport_print_data(
        const stop_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    stop_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    stop_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    stop_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    stop_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply *out,
        const stop_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const stop_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    stop_replyPlugin_deserialize_from_cdr_buffer(
        stop_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    stop_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    stop_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    stop_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        stop_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    stop_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    stop_replyPlugin_delete(struct PRESTypePlugin *);

    #define turn_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define turn_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define turn_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define turn_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define turn_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern turn_req*
    turn_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern turn_req*
    turn_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern turn_req*
    turn_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    turn_reqPluginSupport_copy_data(
        turn_req *out,
        const turn_req *in);

    NDDSUSERDllExport extern void 
    turn_reqPluginSupport_destroy_data_w_params(
        turn_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    turn_reqPluginSupport_destroy_data_ex(
        turn_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    turn_reqPluginSupport_destroy_data(
        turn_req *sample);

    NDDSUSERDllExport extern void 
    turn_reqPluginSupport_print_data(
        const turn_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    turn_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    turn_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    turn_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    turn_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    turn_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        turn_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    turn_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        turn_req *out,
        const turn_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    turn_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const turn_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    turn_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        turn_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    turn_reqPlugin_deserialize_from_cdr_buffer(
        turn_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    turn_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    turn_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    turn_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    turn_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    turn_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        turn_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    turn_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    turn_reqPlugin_delete(struct PRESTypePlugin *);

    #define turn_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define turn_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define turn_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define turn_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define turn_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern turn_reply*
    turn_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern turn_reply*
    turn_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern turn_reply*
    turn_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    turn_replyPluginSupport_copy_data(
        turn_reply *out,
        const turn_reply *in);

    NDDSUSERDllExport extern void 
    turn_replyPluginSupport_destroy_data_w_params(
        turn_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    turn_replyPluginSupport_destroy_data_ex(
        turn_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    turn_replyPluginSupport_destroy_data(
        turn_reply *sample);

    NDDSUSERDllExport extern void 
    turn_replyPluginSupport_print_data(
        const turn_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    turn_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    turn_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    turn_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    turn_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    turn_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        turn_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    turn_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        turn_reply *out,
        const turn_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    turn_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const turn_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    turn_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        turn_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    turn_replyPlugin_deserialize_from_cdr_buffer(
        turn_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    turn_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    turn_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    turn_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    turn_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    turn_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        turn_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    turn_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    turn_replyPlugin_delete(struct PRESTypePlugin *);

    #define zero_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define zero_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define zero_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define zero_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define zero_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern zero_req*
    zero_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern zero_req*
    zero_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern zero_req*
    zero_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    zero_reqPluginSupport_copy_data(
        zero_req *out,
        const zero_req *in);

    NDDSUSERDllExport extern void 
    zero_reqPluginSupport_destroy_data_w_params(
        zero_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    zero_reqPluginSupport_destroy_data_ex(
        zero_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    zero_reqPluginSupport_destroy_data(
        zero_req *sample);

    NDDSUSERDllExport extern void 
    zero_reqPluginSupport_print_data(
        const zero_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    zero_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    zero_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    zero_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    zero_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    zero_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        zero_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    zero_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        zero_req *out,
        const zero_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    zero_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const zero_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    zero_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        zero_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    zero_reqPlugin_deserialize_from_cdr_buffer(
        zero_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    zero_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    zero_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    zero_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    zero_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    zero_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        zero_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    zero_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    zero_reqPlugin_delete(struct PRESTypePlugin *);

    #define zero_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define zero_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define zero_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define zero_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define zero_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern zero_reply*
    zero_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern zero_reply*
    zero_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern zero_reply*
    zero_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    zero_replyPluginSupport_copy_data(
        zero_reply *out,
        const zero_reply *in);

    NDDSUSERDllExport extern void 
    zero_replyPluginSupport_destroy_data_w_params(
        zero_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    zero_replyPluginSupport_destroy_data_ex(
        zero_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    zero_replyPluginSupport_destroy_data(
        zero_reply *sample);

    NDDSUSERDllExport extern void 
    zero_replyPluginSupport_print_data(
        const zero_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    zero_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    zero_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    zero_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    zero_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    zero_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        zero_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    zero_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        zero_reply *out,
        const zero_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    zero_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const zero_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    zero_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        zero_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    zero_replyPlugin_deserialize_from_cdr_buffer(
        zero_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    zero_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    zero_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    zero_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    zero_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    zero_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        zero_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    zero_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    zero_replyPlugin_delete(struct PRESTypePlugin *);

    #define angleTargetPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define angleTargetPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define angleTargetPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define angleTargetPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define angleTargetPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern angleTarget*
    angleTargetPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern angleTarget*
    angleTargetPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern angleTarget*
    angleTargetPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    angleTargetPluginSupport_copy_data(
        angleTarget *out,
        const angleTarget *in);

    NDDSUSERDllExport extern void 
    angleTargetPluginSupport_destroy_data_w_params(
        angleTarget *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    angleTargetPluginSupport_destroy_data_ex(
        angleTarget *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    angleTargetPluginSupport_destroy_data(
        angleTarget *sample);

    NDDSUSERDllExport extern void 
    angleTargetPluginSupport_print_data(
        const angleTarget *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    angleTargetPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    angleTargetPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    angleTargetPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    angleTargetPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    angleTargetPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        angleTarget *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    angleTargetPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        angleTarget *out,
        const angleTarget *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    angleTargetPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const angleTarget *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    angleTargetPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        angleTarget **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    angleTargetPlugin_deserialize_from_cdr_buffer(
        angleTarget *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    angleTargetPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    angleTargetPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    angleTargetPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    angleTargetPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    angleTargetPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        angleTarget ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    angleTargetPlugin_new(void);

    NDDSUSERDllExport extern void
    angleTargetPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskActServo  */
namespace DdsJobWzskActLaser {

    #define setLeft_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setLeft_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setLeft_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setLeft_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setLeft_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setLeft_req*
    setLeft_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setLeft_req*
    setLeft_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setLeft_req*
    setLeft_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setLeft_reqPluginSupport_copy_data(
        setLeft_req *out,
        const setLeft_req *in);

    NDDSUSERDllExport extern void 
    setLeft_reqPluginSupport_destroy_data_w_params(
        setLeft_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setLeft_reqPluginSupport_destroy_data_ex(
        setLeft_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setLeft_reqPluginSupport_destroy_data(
        setLeft_req *sample);

    NDDSUSERDllExport extern void 
    setLeft_reqPluginSupport_print_data(
        const setLeft_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setLeft_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setLeft_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setLeft_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setLeft_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setLeft_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setLeft_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_req *out,
        const setLeft_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setLeft_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setLeft_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setLeft_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setLeft_reqPlugin_deserialize_from_cdr_buffer(
        setLeft_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setLeft_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setLeft_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setLeft_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setLeft_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setLeft_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setLeft_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setLeft_reqPlugin_delete(struct PRESTypePlugin *);

    #define setLeft_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setLeft_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setLeft_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setLeft_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setLeft_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setLeft_reply*
    setLeft_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setLeft_reply*
    setLeft_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setLeft_reply*
    setLeft_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setLeft_replyPluginSupport_copy_data(
        setLeft_reply *out,
        const setLeft_reply *in);

    NDDSUSERDllExport extern void 
    setLeft_replyPluginSupport_destroy_data_w_params(
        setLeft_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setLeft_replyPluginSupport_destroy_data_ex(
        setLeft_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setLeft_replyPluginSupport_destroy_data(
        setLeft_reply *sample);

    NDDSUSERDllExport extern void 
    setLeft_replyPluginSupport_print_data(
        const setLeft_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setLeft_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setLeft_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setLeft_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setLeft_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setLeft_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setLeft_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_reply *out,
        const setLeft_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setLeft_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setLeft_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setLeft_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setLeft_replyPlugin_deserialize_from_cdr_buffer(
        setLeft_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setLeft_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setLeft_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setLeft_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setLeft_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setLeft_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setLeft_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setLeft_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setLeft_replyPlugin_delete(struct PRESTypePlugin *);

    #define setRight_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRight_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRight_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRight_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRight_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRight_req*
    setRight_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRight_req*
    setRight_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRight_req*
    setRight_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRight_reqPluginSupport_copy_data(
        setRight_req *out,
        const setRight_req *in);

    NDDSUSERDllExport extern void 
    setRight_reqPluginSupport_destroy_data_w_params(
        setRight_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRight_reqPluginSupport_destroy_data_ex(
        setRight_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRight_reqPluginSupport_destroy_data(
        setRight_req *sample);

    NDDSUSERDllExport extern void 
    setRight_reqPluginSupport_print_data(
        const setRight_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRight_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRight_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRight_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRight_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRight_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRight_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRight_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRight_req *out,
        const setRight_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRight_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRight_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRight_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRight_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRight_reqPlugin_deserialize_from_cdr_buffer(
        setRight_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRight_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRight_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRight_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRight_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRight_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRight_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRight_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setRight_reqPlugin_delete(struct PRESTypePlugin *);

    #define setRight_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setRight_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setRight_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setRight_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setRight_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setRight_reply*
    setRight_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setRight_reply*
    setRight_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setRight_reply*
    setRight_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setRight_replyPluginSupport_copy_data(
        setRight_reply *out,
        const setRight_reply *in);

    NDDSUSERDllExport extern void 
    setRight_replyPluginSupport_destroy_data_w_params(
        setRight_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setRight_replyPluginSupport_destroy_data_ex(
        setRight_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setRight_replyPluginSupport_destroy_data(
        setRight_reply *sample);

    NDDSUSERDllExport extern void 
    setRight_replyPluginSupport_print_data(
        const setRight_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setRight_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setRight_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setRight_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setRight_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setRight_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRight_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setRight_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setRight_reply *out,
        const setRight_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setRight_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setRight_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setRight_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setRight_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setRight_replyPlugin_deserialize_from_cdr_buffer(
        setRight_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setRight_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setRight_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setRight_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setRight_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setRight_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setRight_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setRight_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setRight_replyPlugin_delete(struct PRESTypePlugin *);

    #define leftRightPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define leftRightPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define leftRightPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define leftRightPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define leftRightPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern leftRight*
    leftRightPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    leftRightPluginSupport_copy_data(
        leftRight *out,
        const leftRight *in);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data_w_params(
        leftRight *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data_ex(
        leftRight *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_destroy_data(
        leftRight *sample);

    NDDSUSERDllExport extern void 
    leftRightPluginSupport_print_data(
        const leftRight *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    leftRightPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    leftRightPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    leftRightPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    leftRightPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    leftRightPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        leftRight *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        leftRight *out,
        const leftRight *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    leftRightPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const leftRight *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        leftRight **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    leftRightPlugin_deserialize_from_cdr_buffer(
        leftRight *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    leftRightPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    leftRightPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    leftRightPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        leftRight ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    leftRightPlugin_new(void);

    NDDSUSERDllExport extern void
    leftRightPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskActLaser  */
namespace DdsJobWzskActExposure {

    #define setExposure_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setExposure_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setExposure_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setExposure_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setExposure_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setExposure_req*
    setExposure_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setExposure_req*
    setExposure_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setExposure_req*
    setExposure_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setExposure_reqPluginSupport_copy_data(
        setExposure_req *out,
        const setExposure_req *in);

    NDDSUSERDllExport extern void 
    setExposure_reqPluginSupport_destroy_data_w_params(
        setExposure_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setExposure_reqPluginSupport_destroy_data_ex(
        setExposure_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setExposure_reqPluginSupport_destroy_data(
        setExposure_req *sample);

    NDDSUSERDllExport extern void 
    setExposure_reqPluginSupport_print_data(
        const setExposure_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setExposure_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setExposure_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setExposure_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setExposure_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setExposure_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setExposure_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_req *out,
        const setExposure_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setExposure_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setExposure_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setExposure_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setExposure_reqPlugin_deserialize_from_cdr_buffer(
        setExposure_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setExposure_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setExposure_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setExposure_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setExposure_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setExposure_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setExposure_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setExposure_reqPlugin_delete(struct PRESTypePlugin *);

    #define setExposure_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setExposure_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setExposure_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setExposure_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setExposure_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setExposure_reply*
    setExposure_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setExposure_reply*
    setExposure_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setExposure_reply*
    setExposure_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setExposure_replyPluginSupport_copy_data(
        setExposure_reply *out,
        const setExposure_reply *in);

    NDDSUSERDllExport extern void 
    setExposure_replyPluginSupport_destroy_data_w_params(
        setExposure_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setExposure_replyPluginSupport_destroy_data_ex(
        setExposure_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setExposure_replyPluginSupport_destroy_data(
        setExposure_reply *sample);

    NDDSUSERDllExport extern void 
    setExposure_replyPluginSupport_print_data(
        const setExposure_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setExposure_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setExposure_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setExposure_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setExposure_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setExposure_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setExposure_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_reply *out,
        const setExposure_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setExposure_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setExposure_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setExposure_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setExposure_replyPlugin_deserialize_from_cdr_buffer(
        setExposure_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setExposure_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setExposure_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setExposure_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setExposure_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setExposure_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setExposure_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setExposure_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setExposure_replyPlugin_delete(struct PRESTypePlugin *);

    #define setFocus_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setFocus_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setFocus_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_req*
    setFocus_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPluginSupport_copy_data(
        setFocus_req *out,
        const setFocus_req *in);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_w_params(
        setFocus_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data_ex(
        setFocus_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_destroy_data(
        setFocus_req *sample);

    NDDSUSERDllExport extern void 
    setFocus_reqPluginSupport_print_data(
        const setFocus_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req *out,
        const setFocus_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_reqPlugin_deserialize_from_cdr_buffer(
        setFocus_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_reqPlugin_delete(struct PRESTypePlugin *);

    #define setFocus_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setFocus_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setFocus_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setFocus_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setFocus_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setFocus_reply*
    setFocus_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPluginSupport_copy_data(
        setFocus_reply *out,
        const setFocus_reply *in);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_w_params(
        setFocus_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data_ex(
        setFocus_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_destroy_data(
        setFocus_reply *sample);

    NDDSUSERDllExport extern void 
    setFocus_replyPluginSupport_print_data(
        const setFocus_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setFocus_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setFocus_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setFocus_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setFocus_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply *out,
        const setFocus_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setFocus_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setFocus_replyPlugin_deserialize_from_cdr_buffer(
        setFocus_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setFocus_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setFocus_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setFocus_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setFocus_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setFocus_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setFocus_replyPlugin_delete(struct PRESTypePlugin *);

    #define autoNotManualTexpPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define autoNotManualTexpPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define autoNotManualTexpPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define autoNotManualTexpPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define autoNotManualTexpPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern autoNotManualTexp*
    autoNotManualTexpPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern autoNotManualTexp*
    autoNotManualTexpPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern autoNotManualTexp*
    autoNotManualTexpPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    autoNotManualTexpPluginSupport_copy_data(
        autoNotManualTexp *out,
        const autoNotManualTexp *in);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPluginSupport_destroy_data_w_params(
        autoNotManualTexp *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPluginSupport_destroy_data_ex(
        autoNotManualTexp *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPluginSupport_destroy_data(
        autoNotManualTexp *sample);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPluginSupport_print_data(
        const autoNotManualTexp *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    autoNotManualTexpPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    autoNotManualTexpPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    autoNotManualTexpPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    autoNotManualTexpPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        autoNotManualTexp *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    autoNotManualTexpPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        autoNotManualTexp *out,
        const autoNotManualTexp *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    autoNotManualTexpPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const autoNotManualTexp *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    autoNotManualTexpPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        autoNotManualTexp **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    autoNotManualTexpPlugin_deserialize_from_cdr_buffer(
        autoNotManualTexp *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    autoNotManualTexpPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    autoNotManualTexpPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    autoNotManualTexpPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    autoNotManualTexpPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    autoNotManualTexpPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        autoNotManualTexp ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    autoNotManualTexpPlugin_new(void);

    NDDSUSERDllExport extern void
    autoNotManualTexpPlugin_delete(struct PRESTypePlugin *);

    #define focusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define focusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define focusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define focusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define focusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern focus*
    focusPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern focus*
    focusPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern focus*
    focusPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    focusPluginSupport_copy_data(
        focus *out,
        const focus *in);

    NDDSUSERDllExport extern void 
    focusPluginSupport_destroy_data_w_params(
        focus *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    focusPluginSupport_destroy_data_ex(
        focus *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    focusPluginSupport_destroy_data(
        focus *sample);

    NDDSUSERDllExport extern void 
    focusPluginSupport_print_data(
        const focus *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    focusPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    focusPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    focusPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    focusPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    focusPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        focus *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    focusPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        focus *out,
        const focus *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    focusPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const focus *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    focusPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        focus **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    focusPlugin_deserialize_from_cdr_buffer(
        focus *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    focusPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    focusPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    focusPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    focusPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    focusPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        focus ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    focusPlugin_new(void);

    NDDSUSERDllExport extern void
    focusPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskActExposure  */
namespace DdsJobWzskAcqPtcloud {

    #define setDeltaTheta_reqPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setDeltaTheta_reqPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setDeltaTheta_reqPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setDeltaTheta_reqPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setDeltaTheta_reqPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setDeltaTheta_req*
    setDeltaTheta_reqPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setDeltaTheta_req*
    setDeltaTheta_reqPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setDeltaTheta_req*
    setDeltaTheta_reqPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_reqPluginSupport_copy_data(
        setDeltaTheta_req *out,
        const setDeltaTheta_req *in);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPluginSupport_destroy_data_w_params(
        setDeltaTheta_req *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPluginSupport_destroy_data_ex(
        setDeltaTheta_req *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPluginSupport_destroy_data(
        setDeltaTheta_req *sample);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPluginSupport_print_data(
        const setDeltaTheta_req *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setDeltaTheta_reqPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setDeltaTheta_reqPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setDeltaTheta_reqPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setDeltaTheta_reqPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_req *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_reqPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_req *out,
        const setDeltaTheta_req *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setDeltaTheta_reqPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setDeltaTheta_req *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_reqPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_req **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setDeltaTheta_reqPlugin_deserialize_from_cdr_buffer(
        setDeltaTheta_req *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_reqPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setDeltaTheta_reqPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_reqPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_reqPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_reqPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_req ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setDeltaTheta_reqPlugin_new(void);

    NDDSUSERDllExport extern void
    setDeltaTheta_reqPlugin_delete(struct PRESTypePlugin *);

    #define setDeltaTheta_replyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define setDeltaTheta_replyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define setDeltaTheta_replyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define setDeltaTheta_replyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define setDeltaTheta_replyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern setDeltaTheta_reply*
    setDeltaTheta_replyPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern setDeltaTheta_reply*
    setDeltaTheta_replyPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern setDeltaTheta_reply*
    setDeltaTheta_replyPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_replyPluginSupport_copy_data(
        setDeltaTheta_reply *out,
        const setDeltaTheta_reply *in);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPluginSupport_destroy_data_w_params(
        setDeltaTheta_reply *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPluginSupport_destroy_data_ex(
        setDeltaTheta_reply *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPluginSupport_destroy_data(
        setDeltaTheta_reply *sample);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPluginSupport_print_data(
        const setDeltaTheta_reply *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    setDeltaTheta_replyPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    setDeltaTheta_replyPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    setDeltaTheta_replyPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    setDeltaTheta_replyPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_reply *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_replyPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_reply *out,
        const setDeltaTheta_reply *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    setDeltaTheta_replyPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const setDeltaTheta_reply *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_replyPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_reply **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    setDeltaTheta_replyPlugin_deserialize_from_cdr_buffer(
        setDeltaTheta_reply *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_replyPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    setDeltaTheta_replyPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_replyPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    setDeltaTheta_replyPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    setDeltaTheta_replyPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        setDeltaTheta_reply ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    setDeltaTheta_replyPlugin_new(void);

    NDDSUSERDllExport extern void
    setDeltaTheta_replyPlugin_delete(struct PRESTypePlugin *);

    #define deltaThetaPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define deltaThetaPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define deltaThetaPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define deltaThetaPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define deltaThetaPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern deltaTheta*
    deltaThetaPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern deltaTheta*
    deltaThetaPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern deltaTheta*
    deltaThetaPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    deltaThetaPluginSupport_copy_data(
        deltaTheta *out,
        const deltaTheta *in);

    NDDSUSERDllExport extern void 
    deltaThetaPluginSupport_destroy_data_w_params(
        deltaTheta *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    deltaThetaPluginSupport_destroy_data_ex(
        deltaTheta *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    deltaThetaPluginSupport_destroy_data(
        deltaTheta *sample);

    NDDSUSERDllExport extern void 
    deltaThetaPluginSupport_print_data(
        const deltaTheta *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    deltaThetaPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    deltaThetaPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    deltaThetaPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    deltaThetaPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    deltaThetaPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        deltaTheta *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    deltaThetaPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        deltaTheta *out,
        const deltaTheta *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    deltaThetaPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const deltaTheta *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    deltaThetaPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        deltaTheta **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    deltaThetaPlugin_deserialize_from_cdr_buffer(
        deltaTheta *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    deltaThetaPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    deltaThetaPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    deltaThetaPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    deltaThetaPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    deltaThetaPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        deltaTheta ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    deltaThetaPlugin_new(void);

    NDDSUSERDllExport extern void
    deltaThetaPlugin_delete(struct PRESTypePlugin *);

    #define xYZPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define xYZPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define xYZPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define xYZPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define xYZPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern xYZ*
    xYZPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern xYZ*
    xYZPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern xYZ*
    xYZPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    xYZPluginSupport_copy_data(
        xYZ *out,
        const xYZ *in);

    NDDSUSERDllExport extern void 
    xYZPluginSupport_destroy_data_w_params(
        xYZ *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    xYZPluginSupport_destroy_data_ex(
        xYZ *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    xYZPluginSupport_destroy_data(
        xYZ *sample);

    NDDSUSERDllExport extern void 
    xYZPluginSupport_print_data(
        const xYZ *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    xYZPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    xYZPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    xYZPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    xYZPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    xYZPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        xYZ *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    xYZPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        xYZ *out,
        const xYZ *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    xYZPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const xYZ *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    xYZPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        xYZ **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    xYZPlugin_deserialize_from_cdr_buffer(
        xYZ *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    xYZPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    xYZPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    xYZPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    xYZPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    xYZPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        xYZ ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    xYZPlugin_new(void);

    NDDSUSERDllExport extern void
    xYZPlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskAcqPtcloud  */
namespace DdsJobWzskAcqPreview {

    #define grayPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define grayPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define grayPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define grayPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define grayPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern gray*
    grayPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern gray*
    grayPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern gray*
    grayPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    grayPluginSupport_copy_data(
        gray *out,
        const gray *in);

    NDDSUSERDllExport extern void 
    grayPluginSupport_destroy_data_w_params(
        gray *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    grayPluginSupport_destroy_data_ex(
        gray *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    grayPluginSupport_destroy_data(
        gray *sample);

    NDDSUSERDllExport extern void 
    grayPluginSupport_print_data(
        const gray *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    grayPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    grayPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    grayPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    grayPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    grayPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        gray *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    grayPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        gray *out,
        const gray *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    grayPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const gray *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    grayPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        gray **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    grayPlugin_deserialize_from_cdr_buffer(
        gray *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    grayPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    grayPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    grayPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    grayPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    grayPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        gray ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    grayPlugin_new(void);

    NDDSUSERDllExport extern void
    grayPlugin_delete(struct PRESTypePlugin *);

    #define redGreenBluePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define redGreenBluePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define redGreenBluePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define redGreenBluePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define redGreenBluePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern redGreenBlue*
    redGreenBluePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern redGreenBlue*
    redGreenBluePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern redGreenBlue*
    redGreenBluePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    redGreenBluePluginSupport_copy_data(
        redGreenBlue *out,
        const redGreenBlue *in);

    NDDSUSERDllExport extern void 
    redGreenBluePluginSupport_destroy_data_w_params(
        redGreenBlue *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    redGreenBluePluginSupport_destroy_data_ex(
        redGreenBlue *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    redGreenBluePluginSupport_destroy_data(
        redGreenBlue *sample);

    NDDSUSERDllExport extern void 
    redGreenBluePluginSupport_print_data(
        const redGreenBlue *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    redGreenBluePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    redGreenBluePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    redGreenBluePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    redGreenBluePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    redGreenBluePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        redGreenBlue *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    redGreenBluePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        redGreenBlue *out,
        const redGreenBlue *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    redGreenBluePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const redGreenBlue *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    redGreenBluePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        redGreenBlue **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    redGreenBluePlugin_deserialize_from_cdr_buffer(
        redGreenBlue *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    redGreenBluePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    redGreenBluePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    redGreenBluePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    redGreenBluePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    redGreenBluePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        redGreenBlue ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    redGreenBluePlugin_new(void);

    NDDSUSERDllExport extern void
    redGreenBluePlugin_delete(struct PRESTypePlugin *);

} /* namespace DdsJobWzskAcqPreview  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* DdsWzskPlugin_509372353_h */

