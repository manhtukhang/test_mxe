#ifndef _VMR9_H
#define _VMR9_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXTERN_C const IID IID_IVMRFilterConfig9;
EXTERN_C const IID IID_IVMRWindowlessControl9;
EXTERN_C const IID IID_IVMRMixerControl9;

/*--- DirectShow Reference - DirectShow Enumerated Types */
typedef enum _VMR9_SampleFormat {
	VMR9_SampleReserved = 1,
	VMR9_SampleProgressiveFrame = 2,
	VMR9_SampleFieldInterleavedEvenFirst = 3,
	VMR9_SampleFieldInterleavedOddFirst = 4,
	VMR9_SampleFieldSingleEven = 5,
	VMR9_SampleFieldSingleOdd = 6
} VMR9_SampleFormat;
typedef enum {
	VMR9AlphaBitmap_Disable = 0x00000001,
	VMR9AlphaBitmap_hDC = 0x00000002,
	VMR9AlphaBitmap_EntireDDS = 0x00000004,
	VMR9AlphaBitmap_SrcColorKey = 0x00000008,
	VMR9AlphaBitmap_SrcRect = 0x00000010,
	VMR9AlphaBitmap_FilterMode = 0x00000020
} VMR9AlphaBitmapFlags;
typedef enum {
	VMR9ARMode_None,
	VMR9ARMode_LetterBox
} VMR9AspectRatioMode;
typedef enum {
	DeinterlacePref9_NextBest = 0x01,
	DeinterlacePref9_BOB = 0x02,
	DeinterlacePref9_Weave = 0x04,
	DeinterlacePref9_Mask = 0x07
} VMR9DeinterlacePrefs;
typedef enum {
	DeinterlaceTech9_Unknown = 0x0000,
	DeinterlaceTech9_BOBLineReplicate = 0x0001,
	DeinterlaceTech9_BOBVerticalStretch = 0x0002,
	DeinterlaceTech9_MedianFiltering = 0x0004,
	DeinterlaceTech9_EdgeFiltering = 0x0010,
	DeinterlaceTech9_FieldAdaptive = 0x0020,
	DeinterlaceTech9_PixelAdaptive = 0x0040,
	DeinterlaceTech9_MotionVectorSteered = 0x0080
} VMR9DeinterlaceTech;
typedef enum {
	MixerPref9_NoDecimation = 0x00000001,
	MixerPref9_DecimateOutput = 0x00000002,
	MixerPref9_ARAdjustXorY = 0x00000004,
	MixerPref9_NonSquareMixing = 0x00000008,
	MixerPref9_DecimateMask = 0x0000000F,
	MixerPref9_BiLinearFiltering = 0x00000010,
	MixerPref9_PointFiltering = 0x00000020,
	MixerPref9_AnisotropicFiltering = 0x00000040,
	MixerPref9_PyramidalQuadFiltering = 0x00000080,
	MixerPref9_GaussianQuadFiltering = 0x00000100,
	MixerPref9_FilteringReserved = 0x00000E00,
	MixerPref9_FilteringMask = 0x00000FF0,
	MixerPref9_RenderTargetRGB = 0x00001000,
	MixerPref9_RenderTargetYUV = 0x00002000,
	MixerPref9_RenderTargetReserved = 0x000FC000,
	MixerPref9_RenderTargetMask = 0x000FF000,
	MixerPref9_DynamicSwitchToBOB = 0x00100000,
	MixerPref9_DynamicDecimateBy2 = 0x00200000,
	MixerPref9_DynamicReserved = 0x00C00000,
	MixerPref9_DynamicMask = 0x00F00000
} VMR9MixerPrefs;
typedef enum VMR9Mode {
	VMR9Mode_Windowed = 0x00000001,
	VMR9Mode_Windowless = 0x00000002,
	VMR9Mode_Renderless = 0x00000004,
	VMR9Mode_Mask = 0x00000007
};
typedef enum {
	VMR9Sample_SyncPoint = 0x00000001,
	VMR9Sample_Preroll = 0x00000002,
	VMR9Sample_Discontinuity = 0x00000004,
	VMR9Sample_TimeValid = 0x00000008
} VMR9PresentationFlags;
typedef enum {
	ProcAmpControl9_Brightness = 0x00000001,
	ProcAmpControl9_Contrast = 0x00000002,
	ProcAmpControl9_Hue = 0x00000004,
	ProcAmpControl9_Saturation = 0x00000008,
	ProcAmpControl9_Mask = 0x0000000F
} VMR9ProcAmpControlFlags;
typedef enum VMR9RenderPrefs {
	RenderPrefs9_DoNotRenderBorder = 0x00000001,
	RenderPrefs9_Mask = 0x00000001
};
typedef enum {
	VMR9AllocFlag_3DRenderTarget = 0x0001,
	VMR9AllocFlag_DXVATarget = 0x0002,
	VMR9AllocFlag_TextureSurface = 0x0004,
	VMR9AllocFlag_OffscreenSurface = 0x0008,
	VMR9AllocFlag_UsageReserved = 0x00F0,
	VMR9AllocFlag_UsageMask = 0x00FF
} VMR9SurfaceAllocationFlags;
/*--- DirectShow Reference - DirectShow Structures */
/**********
typedef struct VMR9AllocationInfo{
	DWORD dwFlags;
	DWORD dwWidth;
	DWORD dwHeight;
	D3DFORMAT Format;
	D3DPOOL Pool;
	DWORD MinBuffers;
	SIZE szAspectRatio;
	SIZE szNativeSize;
};
**********/
typedef struct _VMR9DeinterlaceCaps {
	DWORD dwSize;
	DWORD dwNumPreviousOutputFrames;
	DWORD dwNumForwardRefSamples;
	DWORD dwNumBackwardRefSamples;
	VMRDeinterlaceTech DeinterlaceTechnology;
} VMR9DeinterlaceCaps;
typedef struct _VMR9Frequency {
	DWORD dwNumerator;
	DWORD dwDenominator;
} VMR9Frequency;
typedef struct {
	UINT uDevID;
	RECT rcMonitor;
	HMONITOR hMon;
	DWORD dwFlags;
	wchar_t szDevice[32];
	wchar_t szDescription[512];
	LARGE_INTEGER liDriverVersion;
	DWORD dwVendorId;
	DWORD dwDeviceId;
	DWORD dwSubSysId;
	DWORD dwRevision;
} VMR9MonitorInfo;
typedef struct VMR9NormalizedRect{
	float left;
	float top;
	float right;
	float bottom;
};
/**********
typedef struct {
	DWORD dwFlags;
	IDirect3DSurface9 *lpSurf;
	REFERENCE_TIME rtStart;
	REFERENCE_TIME rtEnd;
	SIZE szAspectRatio;
	RECT rcSrc;
	RECT rcDst;
	DWORD dwReserved1;
	DWORD dwReserved2;
} VMR9PresentationInfo;
**********/
typedef struct _VMR9ProcAmpControl
{
	DWORD dwSize;
	DWORD dwFlags;
	float Contrast;
	float Brightness;
	float Hue;
	float Saturation;
} VMR9ProcAmpControl;
typedef struct _VMR9ProcAmpControlRange
{
	DWORD dwSize;
	VMR9ProcAmpControlFlags dwProperty;
	float MinValue;
	float MaxValue;
	float DefaultValue;
	float StepSize;
} VMR9ProcAmpControlRange;
typedef struct _VMR9VideoDesc {
	DWORD dwSize;
	DWORD dwSampleWidth;
	DWORD dwSampleHeight;
	VMR9_SampleFormat SampleFormat;
	DWORD dwFourCC;
	VMR9Frequency InputSampleFreq;
	VMR9Frequency OutputFrameFreq;
} VMR9VideoDesc;
typedef struct VMR9VideoStreamInfo{
	IDirect3DSurface9 *pddsVideoSurface;
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwStrmID;
	FLOAT fAlpha;
	VMR9NormalizedRect rNormal;
	REFERENCE_TIME rtStart;
	REFERENCE_TIME rtEnd;
	VMR9_SampleFormat SampleFormat;
};
typedef struct VMR9AlphaBitmap{
	DWORD dwFlags;
	HDC hdc;
	IDirect3DSurface9 *pDDS;
	RECT rSrc;
	VMR9NormalizedRect rDest;
	FLOAT fAlpha;
	COLORREF clrSrcKey;
	DWORD dwFilterMode;
};
#define INTERFACE IVMRImageCompositor9
DECLARE_INTERFACE_(IVMRImageCompositor9, IUnknown)
{
    STDMETHOD(InitCompositionDevice)(THIS_ IUnknown *) PURE;
    STDMETHOD(TermCompositionDevice)(THIS_ IUnknown *) PURE;
    STDMETHOD(SetStreamMediaType)(THIS_ DWORD, AM_MEDIA_TYPE *, BOOL) PURE;
    STDMETHOD(CompositeImage)(THIS_ IUnknown *, IDirect3DSurface9 *, AM_MEDIA_TYPE *,
        REFERENCE_TIME, REFERENCE_TIME, D3DCOLOR, VMR9VideoStreamInfo *, UINT) PURE;
};
#undef INTERFACE
#define INTERFACE IVMRFilterConfig9
DECLARE_INTERFACE_(IVMRFilterConfig9, IUnknown)
{
    STDMETHOD(SetImageCompositor)(THIS_ IVMRImageCompositor9 *) PURE;
    STDMETHOD(SetNumberOfStreams)(THIS_ DWORD) PURE;
    STDMETHOD(GetNumberOfStreams)(THIS_ DWORD *) PURE;
    STDMETHOD(SetRenderingPrefs)(THIS_ DWORD) PURE;
    STDMETHOD(GetRenderingPrefs)(THIS_ DWORD *) PURE;
    STDMETHOD(SetRenderingMode)(THIS_ DWORD) PURE;
    STDMETHOD(GetRenderingMode)(THIS_ DWORD *) PURE;
};
#undef INTERFACE
#define INTERFACE IVMRWindowlessControl9
DECLARE_INTERFACE_(IVMRWindowlessControl9, IUnknown)
{
    STDMETHOD(GetNativeVideoSize)(THIS_ LONG *, LONG *, LONG *, LONG *) PURE;
    STDMETHOD(GetMinIdealVideoSize)(THIS_ LONG *, LONG *) PURE;
    STDMETHOD(GetMaxIdealVideoSize)(THIS_ LONG *, LONG *) PURE;
    STDMETHOD(SetVideoPosition)(THIS_ const LPRECT, const LPRECT) PURE;
    STDMETHOD(GetVideoPosition)(THIS_ LPRECT, LPRECT) PURE;
    STDMETHOD(GetAspectRatioMode)(THIS_ DWORD *) PURE;
    STDMETHOD(SetAspectRatioMode)(THIS_ DWORD) PURE;
    STDMETHOD(SetVideoClippingWindow)(THIS_ HWND) PURE;
    STDMETHOD(RepaintVideo)(THIS_ HWND, HDC) PURE;
    STDMETHOD(DisplayModeChanged)(THIS) PURE;
    STDMETHOD(GetCurrentImage)(THIS_ BYTE **) PURE;
    STDMETHOD(SetBorderColor)(THIS_ COLORREF) PURE;
    STDMETHOD(GetBorderColor)(THIS_ COLORREF *) PURE;
};
#undef INTERFACE
#define INTERFACE IVMRMixerControl9
DECLARE_INTERFACE_(IVMRMixerControl9, IUnknown)
{
    STDMETHOD(SetAlpha)(THIS_ DWORD, float) PURE;
    STDMETHOD(GetAlpha)(THIS_ DWORD, float *) PURE;
    STDMETHOD(SetZOrder)(THIS_ DWORD, DWORD) PURE;
    STDMETHOD(GetZOrder)(THIS_ DWORD, DWORD *) PURE;
    STDMETHOD(SetOutputRect)(THIS_ DWORD, const VMR9NormalizedRect *) PURE;
    STDMETHOD(GetOutputRect)(THIS_ DWORD, VMR9NormalizedRect *) PURE;
    STDMETHOD(SetBackgroundClr)(THIS_ COLORREF) PURE;
    STDMETHOD(GetBackgroundClr)(THIS_ COLORREF *) PURE;
    STDMETHOD(SetMixingPrefs)(THIS_ DWORD) PURE;
    STDMETHOD(GetMixingPrefs)(THIS_ DWORD *) PURE;
    STDMETHOD(SetProcAmpControl)(THIS_ DWORD, VMR9ProcAmpControl *) PURE;
    STDMETHOD(GetProcAmpControl)(THIS_ DWORD, VMR9ProcAmpControl *) PURE;
    STDMETHOD(GetProcAmpControlRange)(THIS_ DWORD, VMR9ProcAmpControlRange *) PURE;
};
#undef INTERFACE
#ifdef __cplusplus
}
#endif
#endif
