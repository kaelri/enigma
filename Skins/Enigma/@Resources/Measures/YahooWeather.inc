[MeasureYahooWeather]
Measure=WebParser
Url=https://wxdata.weather.com/wxdata/weather/local/#CurrentCode#?cc=*&unit=#unit#&dayf=6
RegExp="(?siU)<ut>(.*)</ut>.*<ud>(.*)</ud>.*<us>(.*)</us>.*<up>(.*)</up>.*<ur>(.*)</ur>.*<lat>(.*)</lat>.*<lon>(.*)</lon>.*<zone>(.*)</zone>.*<lsup>(.*)</lsup>.*<obst>(.*)</obst>.*<tmp>(.*)</tmp>.*<flik>(.*)</flik>.*<t>(.*)</t>.*<icon>(.*)</icon>.*<r>(.*)</r>.*<d>(.*)</d>.*<s>(.*)</s>.*<gust>(.*)</gust>.*<d>(.*)</d>.*<t>(.*)</t>.*<hmid>(.*)</hmid>.*<vis.(.*)</vis>.*<i>(.*)</i>.*<t>(.*)</t>.*<dewp>(.*)</dewp>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<dayf>.*<day d="0" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<day d="1" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<day d="2" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<day d="3" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<day d="4" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*<day d="5" t="(.*)" dt="(.*)">.*<hi>(.*)</hi>.*<low>(.*)</low>.*<sunr>(.*)</sunr>.*<suns>(.*)</suns>.*<icon>(.*)</icon>.*<t>(.*)</t>.*"
ErrorString="error"
UpdateRate=1800

;-----------------------
; LOCATION

[MeasureWeatherCity]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=10
RegExpSubstitute=1
Substitute="^(.*), (.*), (.*)$":"\1"

[MeasureWeatherRegion]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=10
RegExpSubstitute=1
Substitute="^(.*), (.*), (.*)$":"\2"

[MeasureWeatherCountry]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=10
RegExpSubstitute=1
Substitute="^(.*), (.*), (.*)$":"\3"

;-----------------------
; UNITS

[MeasureWeatherUnitTemp]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=1

[MeasureWeatherUnitDistance]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=2

[MeasureWeatherUnitPressure]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=4

[MeasureWeatherUnitSpeed]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=3

;-----------------------
; WIND

[MeasureWeatherWindChill]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=12

[MeasureWeatherWindDirection]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=19

[MeasureWeatherWindDirectionCardinal]
Measure=Calc
Formula=FLOOR(((MeasureWeatherWindDirection/11.25)+1.5) < 33 ? ((MeasureWeatherWindDirection/11.25)+1.5) : ((MeasureWeatherWindDirection/11.25)+1.5)-32)
Substitute="10":"EbS","11":"ESE","12":"SEbE","13":"SE","14":"SEbS","15":"SSE","16":"SbE","17":"S","18":"SbW","19":"SSW","20":"SWbS","21":"SW","22":"SWbW","23":"WSW","24":"WbSW","25":"W","26":"WbN","27":"WNW","28":"NWbW","29":"NW","30":"NWbN","31":"NNW","32":"NbW","1":"N","2":"NbE","3":"NNE","4":"NEbN","5":"NE","6":"NEbE","7":"ENE","8":"EbN","9":"E"

[MeasureWeatherWindSpeed]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=17

;-----------------------
; ATMOSPHERE

[MeasureWeatherAtmoHumidity]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=21

[MeasureWeatherAtmoVisibility]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=22

[MeasureWeatherAtmoPressure]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=15

[MeasureWeatherAtmoRising]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=16

;--------------------------------
; SUN

[MeasureWeatherSunrise]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=31

[MeasureWeatherSunset]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=32

;--------------------------------
; REGION

[MeasureWeatherTimeZone]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=8

[MeasureWeatherLatitude]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=6

[MeasureWeatherLongitude]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=7


;--------------------------------
; CURRENT

[MeasureWeatherDesc]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=13

[MeasureWeatherIcon]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=14

[MeasureWeatherTemp]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=11

;-------------------------
; DAY 2

[MeasureWeatherDay2Date]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=36
;Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay2Low]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=39

[MeasureWeatherDay2High]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=38

[MeasureWeatherDay2Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay2Low+MeasureWeatherDay2High)/2)

[MeasureWeatherDay2Desc]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=43

[MeasureWeatherDay2Icon]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=42

;-------------------------
; DAY 3

[MeasureWeatherDay3Date]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=44
;Substitute="Sun":"Sunday","Mon":"Monday","Tue":"Tuesday","Wed":"Wednesday","Thu":"Thursday","Fri":"Friday","Sat":"Saturday"

[MeasureWeatherDay3Low]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=47

[MeasureWeatherDay3High]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=46

[MeasureWeatherDay3Average]
Measure=Calc
Formula=ROUND((MeasureWeatherDay3Low+MeasureWeatherDay3High)/2)

[MeasureWeatherDay3Desc]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=51

[MeasureWeatherDay3Icon]
Measure=WebParser
Url=[MeasureYahooWeather]
StringIndex=50

;-----------------------
; LOGO
; Weather.com requires that any application which uses their API include the logo and a link to their website. This section will automatically insert those elements into any skin which uses this measure module. Please do not remove these elements if you are redistributing this file with your own skin.

[YahooWeatherLogo]
Meter=IMAGE
MeterStyle=Style#Variant#Icon
Group=EnigmaMouseover
ImageName=#@#Images\MoxaWeather\Logo.png
H=25
W=25
Hidden=1
LeftMouseUpAction=["http://weather.com/"][!Redraw]
ToolTipText=Powered by Weather.com
