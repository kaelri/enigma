[Variables]
PanelHeight=395
ArrowY=128

;---------------------------------------------------------------------
; MEASURES

;---------------------------------------------------------------------
; METERS

;-----------------------
; INDICATOR ARROW

[Arrow]
Meter=IMAGE
MeterStyle=StyleMenuArrow
Y=#ArrowY#

;-----------------------
; FEEDS

[PanelName]
Meter=STRING
MeterStyle=StyleName | StyleNameFirst
Text=F  E  E  D  S

[PanelNotes]
Meter=STRING
MeterStyle=StyleNotes | StyleNameFirst
Text=Set the web feeds and news feeds displayed by Enigma Reader.
H=24

;-----------------------

[Feed1Name]
Meter=STRING
MeterStyle=StyleName
Text="1st Feed"

[Feed1Text]
Meter=STRING
MeterStyle=StyleText
Text="#Feed1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 1"
TooltipTitle="1st Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

[Feed2Name]
Meter=STRING
MeterStyle=StyleName
Text="2nd Feed"

[Feed2Text]
Meter=STRING
MeterStyle=StyleText
Text="#Feed2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 2"
TooltipTitle="2nd Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

[Feed3Name]
Meter=STRING
MeterStyle=StyleName
Text="3rd Feed"

[Feed3Text]
Meter=STRING
MeterStyle=StyleText
Text="#Feed3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 3"
TooltipTitle="3rd Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

;-----------------------

[GmailUsernameName]
Meter=STRING
MeterStyle=StyleName
Text="Gmail Username"

[GmailUsernameText]
Meter=STRING
MeterStyle=StyleText
Text="#GmailUsername#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 4"
TooltipTitle="Google Account Username"
TooltipText=Click to type your Google username and password here. Enigma Gmail will use this information to retrieve unread messages from your inbox.#CRLF##CRLF#You do not need to include '@gmail.com'.#CRLF##CRLF#Rainmeter may be unable to connect to Gmail if your password contains special characters. If your skins are not displaying properly, try changing your password to one that includes only numbers and letters.

[GmailPasswordName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Password"

[GmailPasswordText]
Meter=STRING
MeterStyle=StyleText
Text="*********"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 5"
TooltipTitle="Google Account Password"
TooltipText=Click to type your Google username and password here. Enigma Gmail will use this information to retrieve unread messages from your inbox.#CRLF##CRLF#You do not need to include '@gmail.com'.#CRLF##CRLF#Rainmeter may be unable to connect to Gmail if your password contains special characters. If your skins are not displaying properly, try changing your password to one that includes only numbers and letters.

[GoogleCalendar1Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="1st Calendar"

[GoogleCalendar1Text]
Meter=STRING
MeterStyle=StyleText
Text="#GoogleCalendar1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 6"
TooltipTitle="1st Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

[GoogleCalendar2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Calendar"

[GoogleCalendar2Text]
Meter=STRING
MeterStyle=StyleText
Text="#GoogleCalendar2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 7"
TooltipTitle="2nd Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

[GoogleCalendar3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Calendar"

[GoogleCalendar3Text]
Meter=STRING
MeterStyle=StyleText
Text="#GoogleCalendar3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 8"
TooltipTitle="3rd Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

;-----------------------

; [TwitterUsernameName]
; Meter=STRING
; MeterStyle=StyleName
; Text="Twitter Username"


; [TwitterUsernameText]
; Meter=STRING
; MeterStyle=StyleText
; Text="#TwitterUsername#"
; LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 9"
; TooltipTitle="SuperTweet Username"
; TooltipText="#TwitterText#"

; [TwitterPasswordName]
; Meter=STRING
; MeterStyle=StyleName | StyleNameSub
; Text="SuperTweet Secret"

; [TwitterPasswordText]
; Meter=STRING
; MeterStyle=StyleText
; Text="*********"
; LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 10"
; TooltipTitle="SuperTweet Secret"
; TooltipText="#TwitterText#"

;-----------------------

[FacebookFeedName]
Meter=STRING
MeterStyle=StyleName
Text="Facebook Feed"

[FacebookFeedText]
Meter=STRING
MeterStyle=StyleText
Text="#FacebookFeed#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 11"
TooltipTitle="Facebook Notifications Feed URL"
TooltipText=Click to type or paste the address of your Facebook notifications feed.#CRLF##CRLF#To find the address:#CRLF#1. Log into Facebook.#CRLF#2. Go to http://www.facebook.com/notifications.php.#CRLF#3. Copy the link location of the button labeled 'Via RSS'.#CRLF#4. Copy the link here.

;-----------------------

[RTMusernameName]
Meter=STRING
MeterStyle=StyleName
Text="Remember the Milk"

[RTMusernameText]
Meter=STRING
MeterStyle=StyleText
Text="#RTMusername#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 12"
TooltipTitle="Remember the Milk Username"
TooltipText=Click to type your Remember the Milk username, password, and the ID numbers of up to three of your lists.

[RTMpasswordName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Password"

[RTMpasswordText]
Meter=STRING
MeterStyle=StyleText
Text="*********"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 13"
TooltipTitle="Remember the Milk Password"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist1Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="1st List ID"

[RTMlist1Text]
Meter=STRING
MeterStyle=StyleText
Text="#RTMlist1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 14"
TooltipTitle="1st List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd List ID"

[RTMlist2Text]
Meter=STRING
MeterStyle=StyleText
Text="#RTMlist2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 15"
TooltipTitle="2nd List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd List ID"

[RTMlist3Text]
Meter=STRING
MeterStyle=StyleText
Text="#RTMlist3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 16"
TooltipTitle="3rd List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

;-----------------------

[RestoreDefaultFeeds]
Meter=STRING
MeterStyle=StyleText | StyleTextSubDefaults
LeftMouseDoubleClickAction=[!WriteKeyValue Variables Feed1 "#DefaultFeed1#" "#Settings#"][!WriteKeyValue Variables Feed2 "#DefaultFeed2#" "#Settings#"][!WriteKeyValue Variables Feed3 "#DefaultFeed3#" "#Settings#"][!WriteKeyValue Variables GmailUsername "#DefaultGmailUsername#" "#Settings#"][!WriteKeyValue Variables GmailPassword "#DefaultGmailPassword#" "#Settings#"][!WriteKeyValue Variables TwitterUsername "#DefaultTwitterUsername#" "#Settings#"][!WriteKeyValue Variables TwitterPassword "#DefaultTwitterPassword#" "#Settings#"][!WriteKeyValue Variables FacebookFeed "#DefaultFacebookFeed#" "#Settings#"][!WriteKeyValue Variables GoogleCalendar1 "#DefaultGoogleCalendar1#" "#Settings#"][!WriteKeyValue Variables GoogleCalendar2 "#DefaultGoogleCalendar2#" "#Settings#"][!WriteKeyValue Variables GoogleCalendar3 "#DefaultGoogleCalendar3#" "#Settings#"][!WriteKeyValue Variables RTMusername "#DefaultRTMusername#" "#Settings#"][!WriteKeyValue Variables RTMpassword "#DefaultRTMpassword#" "#Settings#"][!WriteKeyValue Variables RTMlist1 "#DefaultRTMlist1#" "#Settings#"][!WriteKeyValue Variables RTMlist2 "#DefaultRTMlist2#" "#Settings#"][!WriteKeyValue Variables RTMlist3 "#DefaultRTMlist3#" "#Settings#"][!Refresh *]
TooltipText=Click here to reset all Feed settings to their default values. Be careful: your current settings will be permanently lost.#CRLF##CRLF#To prevent accidental data loss, this button must be double-clicked.