function Initialize()
	EnigmaSettings = SKIN:GetVariable('EnigmaSettings')
	StyleSettings = SELF:GetOption('StyleSettings')
	
	Variables = {
		--GENERAL
		Note1Path = { File = EnigmaSettings },
		Note2Path = { File = EnigmaSettings },
		Note3Path = { File = EnigmaSettings },
		NoteHeight = { File = EnigmaSettings },
		Drive1 = { File = EnigmaSettings },
		Drive2 = { File = EnigmaSettings },
		Drive3 = { File = EnigmaSettings },
		NetworkMaxDownload = { File = EnigmaSettings },
		NetworkMaxUpload = { File = EnigmaSettings },
		CalendarExtraDays = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' },
		},
		CalendarLeadingZeroes = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' },
		},
		CalendarMondays = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'Sunday', 'Monday' },
		},
		GalleryPath = { File = EnigmaSettings },
		GallerySubfolders = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' },
		},
		GalleryRatio = { File = EnigmaSettings },
		GalleryPosition = { File = EnigmaSettings, 
			Loop = { 'Center', 'Tile', 'Stretch', 'Fit', 'Fill' },
		},
		VolumeIncrement = { File = EnigmaSettings },
		TriptychInterval = { File = EnigmaSettings },
		TriptychDisabled = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' },
		},
		--MUSIC
		MusicPlayerType = { File = EnigmaSettings },
		MusicPlayer = { File = EnigmaSettings },
		--FEEDS
		Feed1 = { File = EnigmaSettings },
		Feed2 = { File = EnigmaSettings },
		Feed3 = { File = EnigmaSettings },
		GmailUsername = { File = EnigmaSettings },
		GmailPassword = { File = EnigmaSettings },
		-- TwitterUsername = { File = EnigmaSettings },
		-- TwitterPassword = { File = EnigmaSettings },
		FacebookFeed = { File = EnigmaSettings },
		GoogleCalendar1 = { File = EnigmaSettings },
		GoogleCalendar2 = { File = EnigmaSettings },
		GoogleCalendar3 = { File = EnigmaSettings },
		RTMusername = { File = EnigmaSettings },
		RTMpassword = { File = EnigmaSettings },
		RTMlist1 = { File = EnigmaSettings },
		RTMlist2 = { File = EnigmaSettings },
		RTMlist3 = { File = EnigmaSettings },
		--WORLD
		WeatherCode = { File = EnigmaSettings },
		Unit = { File = EnigmaSettings, 
			Loop = { 'c', 'f' },
			Labels = { 'Celsius', 'Fahrenheit' },
		},
		World1WeatherCode = { File = EnigmaSettings },
		World1DSTOffset = { File = EnigmaSettings },
		World2WeatherCode = { File = EnigmaSettings },
		World2DSTOffset = { File = EnigmaSettings },
		World3WeatherCode = { File = EnigmaSettings },
		World3DSTOffset = { File = EnigmaSettings },
		--APPS
		App1 = { File = EnigmaSettings },
		App1Path = { File = EnigmaSettings },
		App1Label = { File = EnigmaSettings },
		App1Icon = { File = EnigmaSettings },
		App2 = { File = EnigmaSettings },
		App2Path = { File = EnigmaSettings },
		App2Label = { File = EnigmaSettings },
		App2Icon = { File = EnigmaSettings },
		App3 = { File = EnigmaSettings },
		App3Path = { File = EnigmaSettings },
		App3Label = { File = EnigmaSettings },
		App3Icon = { File = EnigmaSettings },
		App4 = { File = EnigmaSettings },
		App4Path = { File = EnigmaSettings },
		App4Label = { File = EnigmaSettings },
		App4Icon = { File = EnigmaSettings },
		App5 = { File = EnigmaSettings },
		App5Path = { File = EnigmaSettings },
		App5Label = { File = EnigmaSettings },
		App5Icon = { File = EnigmaSettings },
		--SEARCH
		Search1 = { File = EnigmaSettings },
		Search1Command = { File = EnigmaSettings },
		Search1Icon = { File = EnigmaSettings },
		Search2 = { File = EnigmaSettings },
		Search2Command = { File = EnigmaSettings },
		Search2Icon = { File = EnigmaSettings },
		Search3 = { File = EnigmaSettings },
		Search3Command = { File = EnigmaSettings },
		Search3Icon = { File = EnigmaSettings },
		Search4 = { File = EnigmaSettings },
		Search4Command = { File = EnigmaSettings },
		Search4Icon = { File = EnigmaSettings },
		Search5 = { File = EnigmaSettings },
		Search5Command = { File = EnigmaSettings },
		Search5Icon = { File = EnigmaSettings },
		--FORMAT
		Stylesheet = { File = EnigmaSettings },
		Color1= { File = StyleSettings },
		ColorLink= { File = StyleSettings },
		ColorBorder= { File = StyleSettings },
		ColorPanel= { File = StyleSettings },
		ColorFilter= { File = StyleSettings },
		ColorTransparent= { File = StyleSettings },
		ColorImage= { File = StyleSettings, 
			Loop = { 'W', 'B' },
			Labels = { 'W', 'B' },
		},
		Size1= { File = StyleSettings },
		Size4= { File = StyleSettings },
		Size3= { File = StyleSettings },
		Size2= { File = StyleSettings },
		Font= { File = StyleSettings },
		HideBordersTop= { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' },
		},
		HideBordersBottom= { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' },
		},
		--LAYOUT
		SidebarWidth= { File = StyleSettings },
		SidebarSpacing= { File = StyleSettings },
		SidebarAlpha= { File = StyleSettings },
		SidebarImage= { File = StyleSettings },
		SecondSidebarImage= { File = StyleSettings },
		TaskbarHeight= { File = StyleSettings },
		TaskbarSpacing= { File = StyleSettings },
		TaskbarAlpha= { File = StyleSettings },
		TaskbarImage= { File = StyleSettings },
		SecondTaskbarImage= { File = StyleSettings }
	}
	
	for a in string.gmatch(SELF:GetOption('LabelsQueue'),'[^%|]+') do
		for i,v in pairs(Variables[a]['Loop']) do
			if v == SKIN:GetVariable(a) then
				SKIN:Bang('!SetVariable', a..'Label', Variables[a]['Labels'][i])
				break
			end
		end
	end
	
end

function Write(Key, Value)
	if not Value then
		Loop = Variables[Key]['Loop']
		for i,v in pairs(Loop) do
			if v == SKIN:GetVariable(Key) then
				Value = Loop[(i % #Loop) + 1]
				break
			end
		end
	end
	SKIN:Bang('!WriteKeyValue', 'Variables', Key, Value, Variables[Key]['File'])
	SKIN:Bang('!Refresh *')
end

function Default(Key, Confirm)
	if Confirm == 1 then
		Write(Key, SKIN:GetVariable('Default'..Key))
	else
		SKIN:Bang('!SetVariable', 'SelectedDefault', Key)
		SKIN:Bang('!ShowMeterGroup', 'Default')
		SKIN:Bang('!Update')
	end
end