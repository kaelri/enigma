function Initialize()
	EnigmaSettings = SKIN:GetVariable('EnigmaSettings')
	StyleSettings = SKIN:GetVariable('StyleSettings')
	
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
		CalendarEventFile = { File = EnigmaSettings },
		CalendarShowEvents = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarExtraDays = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarLeadingZeroes = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarMondays = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'Sunday', 'Monday' }
		},
		GalleryPath = { File = EnigmaSettings },
		GallerySubfolders = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		GalleryRatio = { File = EnigmaSettings },
		GalleryPosition = { File = EnigmaSettings, 
			Loop = { 'Center', 'Tile', 'Stretch', 'Fit', 'Fill' }
		},
		VolumeIncrement = { File = EnigmaSettings },
		TriptychInterval = { File = EnigmaSettings },
		TriptychDisabled = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
		},
		--MUSIC
		MusicPlayerType = { File = EnigmaSettings },
		MusicPlayer = { File = EnigmaSettings },
		--FEEDS
		Feed1 = { File = EnigmaSettings },
		Feed2 = { File = EnigmaSettings },
		Feed3 = { File = EnigmaSettings },
		GmailUsername = { File = EnigmaSettings,
			Flags = 'gmail'
		},
		GmailPassword = { File = EnigmaSettings },
		-- TwitterUsername = { File = EnigmaSettings },
		-- TwitterPassword = { File = EnigmaSettings },
		FacebookFeed = { File = EnigmaSettings },
		GoogleCalendar1 = { File = EnigmaSettings,
			Flags = 'gcal'
		},
		GoogleCalendar2 = { File = EnigmaSettings,
			Flags = 'gcal'
		},
		GoogleCalendar3 = { File = EnigmaSettings,
			Flags = 'gcal'
		},
		GoogleCalendarWriteEvents = { File = EnigmaSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		RTMusername = { File = EnigmaSettings },
		RTMpassword = { File = EnigmaSettings },
		RTMlist1 = { File = EnigmaSettings },
		RTMlist2 = { File = EnigmaSettings },
		RTMlist3 = { File = EnigmaSettings },
		--WORLD
		WeatherCode = { File = EnigmaSettings,
			Dependents = { 'WeatherCodeName', 'WeatherCodeLat', 'WeatherCodeLon' }
		},
		WeatherCodeName = { File = EnigmaSettings },
		WeatherCodeLat = { File = EnigmaSettings },
		WeatherCodeLon = { File = EnigmaSettings },
		Unit = { File = EnigmaSettings, 
			Loop = { 'c', 'f' },
			Labels = { 'Celsius', 'Fahrenheit' }
		},
		World1WeatherCode = { File = EnigmaSettings,
			Dependents = { 'World1WeatherCodeName', 'World1WeatherCodeLat', 'World1WeatherCodeLon' }
		},
		World1WeatherCodeName = { File = EnigmaSettings },
		World1WeatherCodeLat = { File = EnigmaSettings },
		World1WeatherCodeLon = { File = EnigmaSettings },
		World2WeatherCode = { File = EnigmaSettings,
			Dependents = { 'World2WeatherCodeName', 'World2WeatherCodeLat', 'World2WeatherCodeLon' }
		},
		World2WeatherCodeName = { File = EnigmaSettings },
		World2WeatherCodeLat = { File = EnigmaSettings },
		World2WeatherCodeLon = { File = EnigmaSettings },
		World3WeatherCode = { File = EnigmaSettings,
			Dependents = { 'World3WeatherCodeName', 'World3WeatherCodeLat', 'World3WeatherCodeLon' }
		},
		World3WeatherCodeName = { File = EnigmaSettings },
		World3WeatherCodeLat = { File = EnigmaSettings },
		World3WeatherCodeLon = { File = EnigmaSettings },
		--APPS
		App1 = { File = EnigmaSettings },
		App1Path = { File = EnigmaSettings,
			Flags = 'apppath',
			Dependents = { 'App1PathHandle' }
		},
		App1PathHandle = { File = EnigmaSettings },
		App1Label = { File = EnigmaSettings },
		App1Icon = { File = EnigmaSettings },
		App2 = { File = EnigmaSettings },
		App2Path = { File = EnigmaSettings,
			Flags = 'apppath',
			Dependents = { 'App2PathHandle' }
		},
		App2PathHandle = { File = EnigmaSettings },
		App2Label = { File = EnigmaSettings },
		App2Icon = { File = EnigmaSettings },
		App3 = { File = EnigmaSettings },
		App3Path = { File = EnigmaSettings,
			Flags = 'apppath',
			Dependents = { 'App3PathHandle' }
		},
		App3PathHandle = { File = EnigmaSettings },
		App3Label = { File = EnigmaSettings },
		App3Icon = { File = EnigmaSettings },
		App4 = { File = EnigmaSettings },
		App4Path = { File = EnigmaSettings,
			Flags = 'apppath',
			Dependents = { 'App4PathHandle' }
		},
		App1PathHandle = { File = EnigmaSettings },
		App4Label = { File = EnigmaSettings },
		App4Icon = { File = EnigmaSettings },
		App5 = { File = EnigmaSettings },
		App5Path = { File = EnigmaSettings,
			Flags = 'apppath',
			Dependents = { 'App5PathHandle' }
		},
		App1PathHandle = { File = EnigmaSettings },
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
		Color1 = { File = StyleSettings },
		ColorLink = { File = StyleSettings },
		ColorBorder = { File = StyleSettings },
		ColorEvent = { File = StyleSettings },
		ColorPanel = { File = StyleSettings },
		ColorFilter = { File = StyleSettings },
		ColorTransparent = { File = StyleSettings },
		ColorImage = { File = StyleSettings, 
			Loop = { 'W', 'B' },
			Labels = { 'W', 'B' }
		},
		Size1 = { File = StyleSettings },
		Size4 = { File = StyleSettings },
		Size3 = { File = StyleSettings },
		Size2 = { File = StyleSettings },
		Font = { File = StyleSettings },
		SkinBackgroundAlpha  = { File = StyleSettings },
		HideBordersTop = { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
		},
		HideBordersBottom = { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
		},
		--LAYOUT
		SidebarWidth = { File = StyleSettings },
		SidebarSpacingFixed = { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		SidebarAlpha = { File = StyleSettings },
		SidebarImage = { File = StyleSettings },
		SecondSidebarImage = { File = StyleSettings },
		TaskbarHeight = { File = StyleSettings },
		TaskbarSpacingFixed = { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		TaskbarAlpha = { File = StyleSettings },
		TaskbarImage = { File = StyleSettings },
		SecondTaskbarImage = { File = StyleSettings },
		TaskbarMaxSkinWidth  = { File = StyleSettings },
		TaskbarMinSkinWidth  = { File = StyleSettings }
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

function Write(Key, Value, Wait)
	if not Value then
		Loop = Variables[Key]['Loop']
		for i,v in ipairs(Loop) do
			if v == SKIN:GetVariable(Key) then
				Value = Loop[(i % #Loop) + 1]
				break
			end
		end
	elseif Variables[Key]['Flags'] == 'gmail' then
		Value = string.gsub(Value, '@gmail.com', '')
	elseif Variables[Key]['Flags'] == 'gcal' then
		Value = string.gsub(Value, '/basic', '/full')
	elseif Variables[Key]['Flags'] == 'apppath' then
		local DependentKey = Variables[Key]['Dependents'][1]
		if string.match(Value, '%.exe$') then
			local sDir, sName, sExt = string.match(Value, '(.-)([^\\]-)%.([^%.]+)$')
			DependentValue = sName..'.'..sExt
		else
			DependentValue = 'Rainmeter.exe'
		end
		SKIN:Bang('!WriteKeyValue', 'Variables', DependentKey, DependentValue, Variables[DependentKey]['File'])
	end
	SKIN:Bang('!WriteKeyValue', 'Variables', Key, Value, Variables[Key]['File'])
	if not Wait then
		SKIN:Bang('!Refresh *')
	end
end

function Default(Key, Confirm)
	if Confirm == 1 then
		if Variables[Key]['Dependents'] then
			for i,v in ipairs(Variables[Key]['Dependents']) do
				Write(v, SKIN:GetVariable('Default'..v), 'wait')
			end
		end
		Write(Key, SKIN:GetVariable('Default'..Key))
	else
		SKIN:Bang('!SetVariable', 'SelectedDefault', Key)
		SKIN:Bang('!ShowMeterGroup', 'Default')
		SKIN:Bang('!Update')
	end
end