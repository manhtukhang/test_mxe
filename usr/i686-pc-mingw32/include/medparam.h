#ifndef _MEDPARAM_H
#define _MEDPARAM_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define	MP_CAPS_CURVE_INVSQUARE	( MP_CURVE_INVSQUARE )

/* typedefs */
typedef DWORD MP_CAPS;
typedef float MP_DATA;
typedef DWORD MP_TIMEDATA;
typedef DWORD MP_FLAGS;


/* enum */
typedef 
enum _MP_CURVE_TYPE {
    MP_CURVE_JUMP	= 0x1,
	MP_CURVE_LINEAR	= 0x2,
	MP_CURVE_SQUARE	= 0x4,
	MP_CURVE_INVSQUARE	= 0x8,
	MP_CURVE_SINE	= 0x10
} 	MP_CURVE_TYPE;

typedef 
enum _MP_Type {
    MPT_INT	= 0,
	MPT_FLOAT	= ( MPT_INT + 1 ) ,
	MPT_BOOL	= ( MPT_FLOAT + 1 ) ,
	MPT_ENUM	= ( MPT_BOOL + 1 ) ,
	MPT_MAX	= ( MPT_ENUM + 1 ) 
} MP_TYPE;

/* structs */

typedef struct _MP_PARAMINFO {
    MP_TYPE mpType;
    MP_CAPS mopCaps;
    MP_DATA mpdMinValue;
    MP_DATA mpdMaxValue;
    MP_DATA mpdNeutralValue;
    WCHAR szUnitText[32];
    WCHAR szLabel[32];
} MP_PARAMINFO;

typedef struct _MP_ENVELOPE_SEGMENT {
    REFERENCE_TIME rtStart;
    REFERENCE_TIME rtEnd;
    MP_DATA valStart;
    MP_DATA valEnd;
    MP_CURVE_TYPE iCurve;
    MP_FLAGS flags;
} MP_ENVELOPE_SEGMENT;

/* interfaces */
EXTERN_C const IID IID_IMediaParamInfo;
EXTERN_C const IID IID_IMediaParams;

#define INTERFACE IMediaParamInfo
DECLARE_INTERFACE_(IMediaParamInfo, IUnknown)
{
    STDMETHOD(GetParamCount)(THIS_ DWORD *) PURE;
    STDMETHOD(GetParamInfo)(THIS_ DWORD, MP_PARAMINFO *) PURE;
    STDMETHOD(GetParamText)(THIS_ DWORD, WCHAR **) PURE;
    STDMETHOD(GetNumTimeFormats)(THIS_ DWORD *) PURE;
    STDMETHOD(GetSupportedTimeFormat)(THIS_ DWORD, GUID *) PURE;
    STDMETHOD(GetCurrentTimeFormat)(THIS_ GUID *, MP_TIMEDATA *) PURE;
};
#undef INTERFACE
#define INTERFACE IMediaParams
DECLARE_INTERFACE_(IMediaParams, IUnknown)
{
    STDMETHOD(GetParam)(THIS_ DWORD, MP_DATA *) PURE;
    STDMETHOD(SetParam)(THIS_ DWORD, MP_DATA) PURE;
    STDMETHOD(AddEnvelope)(THIS_ DWORD, DWORD, MP_ENVELOPE_SEGMENT *) PURE;
    STDMETHOD(FlushEnvelope)(THIS_ DWORD, REFERENCE_TIME, REFERENCE_TIME) PURE;
    STDMETHOD(SetTimeFormat)(THIS_ GUID, MP_TIMEDATA) PURE;
};
#undef INTERFACE
#ifdef __cplusplus
}
#endif
#endif
