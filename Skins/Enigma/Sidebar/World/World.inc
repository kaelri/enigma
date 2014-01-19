;---------------------------------------------------------------------
; MEASURES

[MeasureUTC]
Measure=Time
TimeZone=0

[MeasureTimeZone]
Measure=Plugin
Plugin=WebParser
Url=https://maps.googleapis.com/maps/api/timezone/xml?location=#CurrentCodeLat#,#CurrentCodeLon#&timestamp=[&MeasureUTC:]&sensor=false
RegExp=(?siU)<raw_offset>(.*)</raw_offset>
StringIndex=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^([^/]*)$":"(\1/3600)"

[MeasureTime]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
DaylightSavingTime=0

[MeasureReal1]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
Format="%#H.%M.%S  ·  %a"
Substitute="Sun":"SUN","Mon":"MON","Tue":"TUE","Wed":"WED","Thu":"THU","Fri":"FRI","Sat":"SAT"
DaylightSavingTime=0

[MeasureReal2]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
Format="%#d %b  ·  %Y"
Substitute="Jan":"JAN","Feb":"FEB","Mar":"MAR","Apr":"APR","May":"MAY","Jun":"JUN","Jul":"JUL","Aug":"AUG","Sep":"SEP","Oct":"OCT","Nov":"NOV","Dec":"DEC"
DaylightSavingTime=0

;---------------------------------------------------------------------
; METERS

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleWorldBackground

[Texture]
Meter=IMAGE
MeterStyle=StyleWorldTexture

[Border]
Meter=IMAGE
MeterStyle=StyleWorldBorder

[Border2]
Meter=IMAGE
MeterStyle=StyleWorldBorder2

;-----------------------
; CLOCK

[Clock]
Meter=IMAGE
MeterStyle=StyleWorldClock

[Seconds]
Meter=ROUNDLINE
MeterStyle=StyleWorldSeconds
MeasureName=MeasureTime

[Hours]
Meter=ROUNDLINE
MeterStyle=StyleWorldSeconds | StyleWorldHours
MeasureName=MeasureTime

[Minutes]
Meter=ROUNDLINE
MeterStyle=StyleWorldSeconds | StyleWorldMinutes
MeasureName=MeasureTime

;-----------------------
; TEXT

[City]
Meter=STRING
MeterStyle=StyleWorldCity
MeasureName=MeasureWeatherCity

[LatLon]
Meter=STRING
MeterStyle=StyleWorldLatLon
MeasureName=MeasureWeatherLatitude
MeasureName2=MeasureWeatherLongitude
Text="%1, %2"

[Digital2]
Meter=STRING
MeterStyle=StyleWorldDigital2
MeasureName=MeasureReal2

;-------------------------
; TEXT 2 and WEATHER

[Icon]
Meter=IMAGE
MeterStyle=StyleWorldIcon
MeasureName=MeasureWeatherIcon

[Text]
Meter=STRING
MeterStyle=StyleWorldText
MeasureName=MeasureWeatherTemp
MeasureName2=MeasureWeatherDesc
Text="%1° · %2"
LeftMouseUpAction=[[MeasureYahooWeather]][!Redraw]

[Digital]
Meter=STRING
MeterStyle=StyleWorldDigital
MeasureName=MeasureReal1