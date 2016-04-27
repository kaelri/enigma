[MeasureYahooWeather]
Measure=Plugin
Plugin=WebParser
UpdateRate=1800
Url=https://query.yahooapis.com/v1/public/yql?q=select * from weather.forecast where woeid=#CurrentCode# AND u="#Unit#"
RegExp=(?siU).*distance="(.*)".*pressure="(.*)".*speed="(.*)".*temperature="(.*)".*city="(.*)".*country="(.*)".*region="(.*)".*chill="(.*)".*direction="(.*)".*speed="(.*)".*humidity="(.*)".*pressure="(.*)".*rising="(.*)".*visibility="(.*)".*sunrise="(.*)".*sunset="(.*)".*<title>.*:.*m .*(.*)</title>.*lat>(.*)<.*long>(.*)<.*condition.*code="(.*)".*temp="(.*)".*text="(.*)".*forecast.*code="(.*)".*day="(.*)".*high="(.*)".*low="(.*)".*text="(.*)".*forecast.*code="(.*)".*day="(.*)".*high="(.*)".*low="(.*)".*text="(.*)".*forecast.*code="(.*)".*day="(.*)".*high="(.*)".*low="(.*)".*text="(.*)".*

;-----------------------
; UNITS

[MeasureWeatherUnitDistance]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=1

[MeasureWeatherUnitPressure]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=2

[MeasureWeatherUnitSpeed]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=3

[MeasureWeatherUnitTemp]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=4

;-----------------------
; LOCATION

[MeasureWeatherCity]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=5

[MeasureWeatherCountry]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=6

[MeasureWeatherRegion]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=7

;-----------------------
; WIND

[MeasureWeatherWindChill]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=8

[MeasureWeatherWindDirection]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=9

[MeasureWeatherWindDirectionCardinal]
Measure=Calc
Formula=FLOOR(((MeasureWeatherWindDirection/11.25)+1.5) < 33 ? ((MeasureWeatherWindDirection/11.25)+1.5) : ((MeasureWeatherWindDirection/11.25)+1.5)-32)
Substitute="10":"EbS","11":"ESE","12":"SEbE","13":"SE","14":"SEbS","15":"SSE","16":"SbE","17":"S","18":"SbW","19":"SSW","20":"SWbS","21":"SW","22":"SWbW","23":"WSW","24":"WbSW","25":"W","26":"WbN","27":"WNW","28":"NWbW","29":"NW","30":"NWbN","31":"NNW","32":"NbW","1":"N","2":"NbE","3":"NNE","4":"NEbN","5":"NE","6":"NEbE","7":"ENE","8":"EbN","9":"E"

[MeasureWeatherWindSpeed]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=10

;-----------------------
; ATMOSPHERE

[MeasureWeatherAtmoHumidity]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=11

[MeasureWeatherAtmoPressure]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=12

[MeasureWeatherAtmoRising]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=13

[MeasureWeatherAtmoVisibility]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=14

;--------------------------------
; SUN

[MeasureWeatherSunrise]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=15

[MeasureWeatherSunset]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=16

;--------------------------------
; REGION

[MeasureWeatherTimeZone]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=17

[MeasureWeatherLatitude]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=18

[MeasureWeatherLongitude]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=19

;--------------------------------
; CURRENT

[MeasureWeatherIcon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=20

[MeasureWeatherTemp]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=21

[MeasureWeatherDesc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=22

;-------------------------
; DAY 2

[MeasureWeatherDay2Icon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=28

[MeasureWeatherDay2Date]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=29
Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay2High]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=30

[MeasureWeatherDay2Low]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=31

[MeasureWeatherDay2Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay2Low+MeasureWeatherDay2High)/2)

[MeasureWeatherDay2Desc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=32

;-------------------------
; DAY 3

[MeasureWeatherDay3Icon]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=33

[MeasureWeatherDay3Date]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=34
Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay3High]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=35

[MeasureWeatherDay3Low]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=36

[MeasureWeatherDay3Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay3Low+MeasureWeatherDay3High)/2)

[MeasureWeatherDay3Desc]
Measure=Plugin
Plugin=WebParser
Url=[MeasureYahooWeather]
StringIndex=37

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
