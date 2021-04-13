#include "ite/itu.h"



extern bool CheckLightCheckBoxOnPress(ITUWidget* widget, char* param);
extern bool DimLightTrackBarOnChanged(ITUWidget* widget, char* param);
extern bool AirWindTrackBarOnChanged(ITUWidget* widget, char* param);
extern bool AirTempMeterOnChanged(ITUWidget* widget, char* param);
extern bool AirModeMeterOnChanged(ITUWidget* widget, char* param);

extern bool AirOnEnter(ITUWidget* widget, char* param);

extern bool AirSetTmpButtonOnPress(ITUWidget* widget, char* param);
extern	bool CheckCurtainButtonOnPress(ITUWidget* widget, char* param);
extern bool AirSetButtonOnPress(ITUWidget* widget, char* param);


ITUActionFunction actionFunctions[] =
{
    

	"CheckLightCheckBoxOnPress", CheckLightCheckBoxOnPress,
	"DimLightTrackBarOnChanged", DimLightTrackBarOnChanged,
	"AirWindTrackBarOnChanged", AirWindTrackBarOnChanged,
	"AirTempMeterOnChanged", AirTempMeterOnChanged,
	"AirModeMeterOnChanged", AirModeMeterOnChanged,
	"AirOnEnter", AirOnEnter,

	"AirSetTmpButtonOnPress", AirSetTmpButtonOnPress,
	"AirSetButtonOnPress", AirSetButtonOnPress,
	"CheckCurtainButtonOnPress", CheckCurtainButtonOnPress,
    NULL, NULL
};
