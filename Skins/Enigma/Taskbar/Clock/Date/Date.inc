;---------------------------------------------------------------------
; MEASURES

[MeasureDate]
Measure=Time
UpdateDivider=60
Format="%d"
Substitute="01":"1st","02":"2nd","03":"3rd","04":"4th","05":"5th","06":"6th","07":"7th","08":"8th","09":"9th","10":"10th","11":"11th","12":"12th","13":"13th","14":"14th","15":"15th","16":"16th","17":"17th","18":"18th","19":"19th","20":"20th","21":"21st","22":"22nd","23":"23rd","24":"24th","25":"25th","26":"26th","27":"27th","28":"28th","29":"29th","30":"30th","31":"31st"

[MeasureMonth]
Measure=Time
UpdateDivider=60
Format="%b"
Substitute="Jan":"JAN","Feb":"FEB","Mar":"MAR","Apr":"APR","May":"MAY","Jun":"JUN","Jul":"JUL","Aug":"AUG","Sep":"SEP","Oct":"OCT","Nov":"NOV","Dec":"DEC"

[MeasureMonthTotal]
Measure=Time
UpdateDivider=60
Format="%b"
Substitute="Jan":"31","Feb":"28","Mar":"31","Apr":"30","May":"31","Jun":"30","Jul":"31","Aug":"31","Sep":"30","Oct":"31","Nov":"30","Dec":"31"

[MeasureBar]
Measure=Calc
DynamicVariables=1
Formula=MeasureDate / [MeasureMonthTotal]

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
MeasureName=MeasureDate

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureMonth