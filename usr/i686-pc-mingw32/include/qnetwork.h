#ifndef _QNETWORK_H
#define _QNETWORK_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(IID_IAMMediaContent,0xFA2AA8F4L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);
DEFINE_GUID(IID_IAMNetworkStatus,0xFA2AA8F3L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

#define INTERFACE IAMMediaContent
DECLARE_INTERFACE_(IAMMediaContent, IDispatch)
{
    STDMETHOD(get_AuthorName)(THIS_ BSTR*) PURE;
    STDMETHOD(get_Title)(THIS_ BSTR*) PURE;
    STDMETHOD(get_Rating)(THIS_ BSTR*) PURE;
    STDMETHOD(get_Description)(THIS_ BSTR*) PURE;
    STDMETHOD(get_Copyright)(THIS_ BSTR*) PURE;
    STDMETHOD(get_BaseURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_LogoURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_LogoIconURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_WatermarkURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_MoreInfoURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_MoreInfoBannerImage)(THIS_ BSTR*) PURE;
    STDMETHOD(get_MoreInfoBannerURL)(THIS_ BSTR*) PURE;
    STDMETHOD(get_MoreInfoText)(THIS_ BSTR*) PURE;
};
#undef INTERFACE
#define INTERFACE(IAMNetworkStatus)
DECLARE_INTERFACE_(IAMNetworkStatus, IDispatch)
{
    STDMETHOD(get_ReceivedPackets)(THIS_ long*) PURE;
    STDMETHOD(get_RecoveredPackets)(THIS_ long*) PURE;
    STDMETHOD(get_LostPackets)(THIS_ long*) PURE;
    STDMETHOD(get_ReceptionQuality)(THIS_ long*) PURE;
    STDMETHOD(get_BufferingCount)(THIS_ long*) PURE;
    STDMETHOD(get_IsBroadcast)(THIS_ VARIANT_BOOL*) PURE;
    STDMETHOD(get_BufferingProgress)(THIS_ long*) PURE;
};
#undef INTERFACE
#ifdef __cplusplus
}
#endif

#endif //_QNETWORK_H