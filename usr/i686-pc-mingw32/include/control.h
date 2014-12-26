#ifndef _CONTROL_H
#define _CONTROL_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*--- DirectShow Reference - DirectShow Data Types */
typedef LONG_PTR OAEVENT;
typedef LONG_PTR OAHWND;
typedef LONG OAFilterState;

DEFINE_GUID(IID_IBasicAudio,0x56a868b3,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);
DEFINE_GUID(IID_IMediaControl,0x56a868b1,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);
DEFINE_GUID(IID_IMediaEvent,0x56a868b6,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);
DEFINE_GUID(IID_IMediaPosition,0x56a868b2,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);

#define INTERFACE IMediaControl
DECLARE_INTERFACE_(IMediaControl, IDispatch)
{
    STDMETHOD(Run)(THIS) PURE;
    STDMETHOD(Pause)(THIS) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(GetState)(THIS_ LONG, OAFilterState *) PURE;
    STDMETHOD(RenderFile)(THIS_ BSTR) PURE;
    STDMETHOD(AddSourceFilter)(THIS_ BSTR, IDispatch **) PURE;
    STDMETHOD(get_FilterCollection)(THIS_ IDispatch **) PURE;
    STDMETHOD(get_RegFilterCollection)(IDispatch **) PURE;
    STDMETHOD(StopWhenReady)(THIS) PURE;
};
#undef INTERFACE    
#define INTERFACE IBasicAudio
DECLARE_INTERFACE_(IBasicAudio, IDispatch)
{
    STDMETHOD(put_Volume)(THIS_ long) PURE;
    STDMETHOD(get_Volume)(THIS_ long *) PURE;
    STDMETHOD(put_Balance)(THIS_ long) PURE;
    STDMETHOD(get_Balance)(THIS_ long *) PURE;
};
#undef INTERFACE
#define INTERFACE IMediaPosition
DECLARE_INTERFACE_(IMediaPosition, IDispatch)
{
    STDMETHOD(get_Duration)(THIS_ REFTIME *) PURE;
    STDMETHOD(put_CurrentPosition)(THIS_ REFTIME) PURE;
    STDMETHOD(get_CurrentPosition)(THIS_ REFTIME *) PURE;
    STDMETHOD(get_StopTime)(THIS_ REFTIME *) PURE;
    STDMETHOD(put_StopTime)(THIS_ REFTIME) PURE;
    STDMETHOD(get_PrerollTime)(THIS_ REFTIME *) PURE;
    STDMETHOD(put_PrerollTime)(THIS_ REFTIME) PURE;
    STDMETHOD(put_Rate)(THIS_ double) PURE;
    STDMETHOD(get_Rate)(THIS_ double *) PURE;
    STDMETHOD(CanSeekForward)(THIS_ LONG *) PURE;
    STDMETHOD(CanSeekBackward)(THIS_ LONG *) PURE;
};
#undef INTERFACE
#define INTERFACE IMediaEvent
DECLARE_INTERFACE_(IMediaEvent, IDispatch)
{
    STDMETHOD(GetEventHandle)(THIS_ OAEVENT *) PURE;
    STDMETHOD(GetEvent)(THIS_ long *, LONG_PTR *, LONG_PTR *, long) PURE;
    STDMETHOD(WaitForCompletion)(THIS_ long,long *) PURE;
    STDMETHOD(CancelDefaultHandling)(THIS_ long) PURE;
    STDMETHOD(RestoreDefaultHandling)(THIS_ long) PURE;
    STDMETHOD(FreeEventParams)(THIS_ long, LONG_PTR, LONG_PTR) PURE;
};
#undef INTERFACE
#ifdef __cplusplus
}
#endif
#endif
