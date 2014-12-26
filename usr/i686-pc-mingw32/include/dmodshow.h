#ifndef _MODSHOW_H
#define _MODSHOW_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(CLSID_DMOWrapperFilter, 0x94297043,0xbd82,0x4dfd,0xb0,0xde,0x81,0x77,0x73,0x9c,0x6d,0x20);
EXTERN_C const IID IID_IDMOWrapperFilter;

#define INTERFACE IDMOWrapperFilter
DECLARE_INTERFACE_(IDMOWrapperFilter, IUnknown)
{
    STDMETHOD(Init)(THIS_ REFCLSID, REFCLSID) PURE;
};
#undef INTERFACE
#ifdef __cplusplus
}
#endif
#endif
