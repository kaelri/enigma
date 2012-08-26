[Variables]
PanelHeight=415
ArrowY=128
LabelsQueue=GoogleCalendarWriteEvents

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
MeterStyle=StyleText | StyleInput
Text="#Feed1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 1"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Feed1')"
TooltipTitle="1st Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

[Feed2Name]
Meter=STRING
MeterStyle=StyleName
Text="2nd Feed"

[Feed2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Feed2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 2"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Feed2')"
TooltipTitle="2nd Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

[Feed3Name]
Meter=STRING
MeterStyle=StyleName
Text="3rd Feed"

[Feed3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#Feed3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 3"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('Feed3')"
TooltipTitle="3rd Feed URL"
TooltipText=Click to type or paste the address of an Atom or RSS feed.

;-----------------------

[GmailUsernameName]
Meter=STRING
MeterStyle=StyleName
Text="Gmail Username"

[GmailUsernameText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#GmailUsername#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 4"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GmailUsername')"
TooltipTitle="Google Account Username"
TooltipText=Click to type your Google username and password here. Enigma Gmail will use this information to retrieve unread messages from your inbox.#CRLF##CRLF#You do not need to include '@gmail.com'.#CRLF##CRLF#Rainmeter may be unable to connect to Gmail if your password contains special characters. If your skins are not displaying properly, try changing your password to one that includes only numbers and letters.

[GmailPasswordName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Password"

[GmailPasswordText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="*********"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 5"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GmailPassword')"
TooltipTitle="Google Account Password"
TooltipText=Click to type your Google username and password here. Enigma Gmail will use this information to retrieve unread messages from your inbox.#CRLF##CRLF#You do not need to include '@gmail.com'.#CRLF##CRLF#Rainmeter may be unable to connect to Gmail if your password contains special characters. If your skins are not displaying properly, try changing your password to one that includes only numbers and letters.

[GoogleCalendar1Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="1st Calendar"

[GoogleCalendar1Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#GoogleCalendar1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 6"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GoogleCalendar1')"
TooltipTitle="1st Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

[GoogleCalendar2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd Calendar"

[GoogleCalendar2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#GoogleCalendar2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 7"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GoogleCalendar2')"
TooltipTitle="2nd Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

[GoogleCalendar3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd Calendar"

[GoogleCalendar3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#GoogleCalendar3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 8"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GoogleCalendar3')"
TooltipTitle="3rd Google Calendar Private Feed URL"
TooltipText=Click to type or paste the addressses of up to three of your Google Calendar feeds.#CRLF##CRLF#To find the address of a feed:#CRLF#1. Go to http://google.com/calendar.#CRLF#2. Find your calendar's tab in the menu on the left.#CRLF#3. Click the triangular button to open its menu, then go to 'Calendar Settings.'#CRLF#4. Scroll down to 'Private Address' and copy the link location of the button labeled 'XML.'#CRLF##CRLF#Google Calendar's feed is notoriously inconsistent. It is very likely that you will notice errors and missing information. The Rainmeter community is doing everything we can to improve the situation, but there is no guaranteed solution at this time.

[GoogleCalendarWriteEventsName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Show Events"

[GoogleCalendarWriteEventsText]
Meter=STRING
MeterStyle=StyleText
LeftMouseUpAction=!CommandMeasure MeasureInputScript "Write('GoogleCalendarWriteEvents')"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('GoogleCalendarWriteEvents')"
TooltipTitle="Write Google Calendar Events to File (Yes/No)"
TooltipText=Click to toggle whether your Calendar skins save your events in a calendar file. If enabled, the file is saved to your Resources folder. You can also select the file to display today's appointments in Enigma Calendar.

;-----------------------

[FacebookFeedName]
Meter=STRING
MeterStyle=StyleName
Text="Facebook Feed"

[FacebookFeedText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#FacebookFeed#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 9"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('FacebookFeed')"
TooltipTitle="Facebook Notifications Feed URL"
TooltipText=Click to type or paste the address of your Facebook notifications feed.#CRLF##CRLF#To find the address:#CRLF#1. Log into Facebook.#CRLF#2. Go to http://www.facebook.com/notifications.php.#CRLF#3. Copy the link location of the button labeled 'Via RSS'.#CRLF#4. Copy the link here.

;-----------------------

[RTMusernameName]
Meter=STRING
MeterStyle=StyleName
Text="Remember the Milk"

[RTMusernameText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#RTMusername#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 10"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('RTMusername')"
TooltipTitle="Remember the Milk Username"
TooltipText=Click to type your Remember the Milk username, password, and the ID numbers of up to three of your lists.

[RTMpasswordName]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="Password"

[RTMpasswordText]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="*********"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 11"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('RTMpassword')"
TooltipTitle="Remember the Milk Password"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist1Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="1st List ID"

[RTMlist1Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#RTMlist1#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 12"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('RTMlist1')"
TooltipTitle="1st List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist2Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="2nd List ID"

[RTMlist2Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#RTMlist2#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 13"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('RTMlist2')"
TooltipTitle="2nd List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

[RTMlist3Name]
Meter=STRING
MeterStyle=StyleName | StyleNameSub
Text="3rd List ID"

[RTMlist3Text]
Meter=STRING
MeterStyle=StyleText | StyleInput
Text="#RTMlist3#"
LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 14"
RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('RTMlist3')"
TooltipTitle="3rd List ID Number"
TooltipText=To find the ID number of a Remember The Milk list:#CRLF#1. Open the list's page on RememberTheMilk.com in your browser.#CRLF#2. Find the link on the far left, labeled 'Atom,' and copy the link address.#CRLF#3. At the end of the address, there will be a number between two slashes. That number is the list ID.#CRLF#Copy the list ID here.

;-----------------------

; [TwitterUsernameName]
; Meter=STRING
; MeterStyle=StyleName
; Text="Twitter Username"


; [TwitterUsernameText]
; Meter=STRING
; MeterStyle=StyleText
; Text="#TwitterUsername#"
; LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 15"
; RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TwitterUsername')"
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
; LeftMouseUpAction=!CommandMeasure "MeasureInputFeeds" "ExecuteBatch 16"
; RightMouseUpAction=!CommandMeasure MeasureInputScript "Default('TwitterPassword')"
; TooltipTitle="SuperTweet Secret"
; TooltipText="#TwitterText#"

;-----------------------

[RestoreDefault]
Meter=STRING
MeterStyle=StyleText | StyleRestoreDefault