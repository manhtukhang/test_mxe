#ifndef _DMO_H
#define _DMO_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _DMO_PARTIAL_MEDIATYPE {
   GUID type;
   GUID subtype;
} DMO_PARTIAL_MEDIATYPE;

typedef enum {
   DMO_ENUMF_INCLUDE_KEYED = 0x00000001
} DMO_ENUM_FLAGS;

DEFINE_GUID(DMOCATEGORY_AUDIO_EFFECT, 0xf3602b3f,0x0592,0x48df,0xa4,0xcd,0x67,0x47,0x21,0xe7,0xeb,0xeb);
DECLARE_INTERFACE(IEnumDMO);

typedef AM_MEDIA_TYPE DMO_MEDIA_TYPE;
STDAPI DMOEnum(REFGUID, DWORD, DWORD, const DMO_PARTIAL_MEDIATYPE *, DWORD, const DMO_PARTIAL_MEDIATYPE *,
               IEnumDMO **);
STDAPI DMOGetName(REFCLSID, WCHAR [80]);


#define INTERFACE IEnumDMO
DECLARE_INTERFACE_(IEnumDMO, IUnknown)
{
    STDMETHOD(Next)(THIS_ DWORD, CLSID *, WCHAR **, DWORD *) PURE;
    STDMETHOD(Skip)(THIS_ DWORD) PURE;
    STDMETHOD(Reset)(THIS) PURE;
    STDMETHOD(Clone)(THIS_ IEnumDMO **) PURE;
};
#undef INTERFACE


#ifdef __cplusplus
}
#endif

#endif //_DMO_H