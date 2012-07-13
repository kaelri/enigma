[MeasureYahooWeather]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=http://weather.yahooapis.com/forecastrss?w=#CurrentCode#&u=#Unit#
RegExp=(?siU)<link.*>(.*)</link>.*city=\"(.*)\".*region=\"(.*)\".*country=\"(.*)\".*temperature=\"(.*)\".*distance=\"(.*)\".*pressure=\"(.*)\".*speed=\"(.*)\".*chill=\"(.*)\".*direction=\"(.*)\".*speed=\"(.*)\".*humidity=\"(.*)\".*visibility=\"(.*)\".*pressure=\"(.*)\".*rising=\"(.*)\".*sunrise=\"(.*)\".*sunset=\"(.*)\".*<title>.*:.*m .*(.*)</title>.*lat>(.*)<.*long>(.*)<.*yweather:condition.*text=\"(.*)\".*code=\"(.*)\".*temp=\"(.*)\".*yweather:forecast.*day=\"(.*)\".*low=\"(.*)\".*high=\"(.*)\".*text=\"(.*)\".*code=\"(.*)\".*yweather:forecast.*day=\"(.*)\".*low=\"(.*)\".*high=\"(.*)\".*text=\"(.*)\".*code=\"(.*)\".*
StringIndex=1

;-----------------------
; LOCATION

[MeasureWeatherCity]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=2

[MeasureWeatherRegion]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=3

[MeasureWeatherCountry]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=4

;-----------------------
; UNITS

[MeasureWeatherUnitTemp]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=5

[MeasureWeatherUnitDistance]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=6

[MeasureWeatherUnitPressure]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=7

[MeasureWeatherUnitSpeed]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=8

;-----------------------
; WIND

[MeasureWeatherWindChill]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=9

[MeasureWeatherWindDirection]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=10

[MeasureWeatherWindDirectionCardinal]
Measure=Calc
Formula=FLOOR(((MeasureWeatherWindDirection/11.25)+1.5) < 33 ? ((MeasureWeatherWindDirection/11.25)+1.5) : ((MeasureWeatherWindDirection/11.25)+1.5)-32)
Substitute="10":"EbS","11":"ESE","12":"SEbE","13":"SE","14":"SEbS","15":"SSE","16":"SbE","17":"S","18":"SbW","19":"SSW","20":"SWbS","21":"SW","22":"SWbW","23":"WSW","24":"WbSW","25":"W","26":"WbN","27":"WNW","28":"NWbW","29":"NW","30":"NWbN","31":"NNW","32":"NbW","1":"N","2":"NbE","3":"NNE","4":"NEbN","5":"NE","6":"NEbE","7":"ENE","8":"EbN","9":"E"

[MeasureWeatherWindSpeed]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=11

;-----------------------
; ATMOSPHERE

[MeasureWeatherAtmoHumidity]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=12

[MeasureWeatherAtmoVisibility]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=13

[MeasureWeatherAtmoPressure]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=14

[MeasureWeatherAtmoRising]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=15

;--------------------------------
; SUN

[MeasureWeatherSunrise]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=16

[MeasureWeatherSunset]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=17

;--------------------------------
; REGION

[MeasureWeatherTimeZone]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=18

[MeasureWeatherLatitude]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=19

[MeasureWeatherLongitude]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=20


;--------------------------------
; CURRENT

[MeasureWeatherDesc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=21

[MeasureWeatherIcon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=22

[MeasureWeatherTemp]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=23

;-------------------------
; DAY 2

[MeasureWeatherDay2Date]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=24
Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay2Low]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=25

[MeasureWeatherDay2High]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=26

[MeasureWeatherDay2Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay2Low+MeasureWeatherDay2High)/2)

[MeasureWeatherDay2Desc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=27

[MeasureWeatherDay2Icon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=28

;-------------------------
; DAY 3

[MeasureWeatherDay3Date]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=29
Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay3Low]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=30

[MeasureWeatherDay3High]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=31

[MeasureWeatherDay3Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay3Low+MeasureWeatherDay3High)/2)

[MeasureWeatherDay3Desc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=32

[MeasureWeatherDay3Icon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=33

;-----------------------
; LOGO
; Yahoo! Weather requires that any application which uses their API include the Y!W logo and a link to their website. This section will automatically insert those elements into any skin which uses this measure module. Please do not remove these elements if you are redistributing this file with your own skin.

[YahooWeatherLogo]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
Group=EnigmaMouseover
ImageName=#@#Images\MoxaWeather\Logo.png
H=25
W=25
Hidden=1
LeftMouseUpAction=["http://weather.yahoo.com/"][!Redraw]
ToolTipText=Powered by Yahoo! Weather.