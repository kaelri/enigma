;---------------------------------------------------------------------
; MEASURES

[MeasureTimeZone]
Measure=Plugin
Plugin=WebParser
UpdateRate=3600
Url=http://ws.geonames.org/timezone?lat=#CurrentCodeLat#&lng=#CurrentCodeLon#
RegExp=<gmtOffset>(.*)</gmtOffset>
StringIndex=1

[MeasureTime]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1

[MeasureReal1]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
Format="%#H.%M.%S  ·  %a"
Substitute="Sun":"SUN","Mon":"MON","Tue":"TUE","Wed":"WED","Thu":"THU","Fri":"FRI","Sat":"SAT"

[MeasureReal2]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
Format="%#d %b  ·  %Y"
Substitute="Jan":"JAN","Feb":"FEB","Mar":"MAR","Apr":"APR","May":"MAY","Jun":"JUN","Jul":"JUL","Aug":"AUG","Sep":"SEP","Oct":"OCT","Nov":"NOV","Dec":"DEC"

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