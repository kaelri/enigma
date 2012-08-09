function Initialize()
	EnigmaSettings = SKIN:GetVariable('EnigmaSettings')
	StyleSettings = SKIN:GetVariable('StyleSettings')
	
	Variables = {
		--GENERAL
		Note1Path = {},
		Note2Path = {},
		Note3Path = {},
		NoteHeight = {},
		Drive1 = {},
		Drive2 = {},
		Drive3 = {},
		NetworkMaxDownload = {},
		NetworkMaxUpload = {},
		SystemGraphType = { Loop = { 'Floating', 'Percent' } },
		CalendarEventFile = {},
		CalendarShowEvents = { Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarExtraDays = { Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarLeadingZeroes = { Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		CalendarMondays = { Loop = { '0', '1' },
			Labels = { 'Sunday', 'Monday' }
		},
		GalleryPath = {},
		GallerySubfolders = { Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		GalleryRatio = {},
		GalleryPosition = { Loop = { 'Center', 'Tile', 'Stretch', 'Fit', 'Fill' } },
		VolumeIncrement = {},
		TriptychInterval = {},
		TriptychDisabled = { Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
		},
		ProcessInterval = {},
		--MUSIC
		MusicPlayerType = {},
		MusicPlayer = {},
		--FEEDS
		Feed1 = {},
		Feed2 = {},
		Feed3 = {},
		GmailUsername = { Flags = 'gmail' },
		GmailPassword = {},
		-- TwitterUsername = {},
		-- TwitterPassword = {},
		FacebookFeed = {},
		GoogleCalendar1 = { Flags = 'gcal' },
		GoogleCalendar2 = { Flags = 'gcal' },
		GoogleCalendar3 = { Flags = 'gcal' },
		GoogleCalendarWriteEvents = { Loop = { '0', '1' },
			Labels = { 'No', 'Yes' }
		},
		RTMusername = {},
		RTMpassword = {},
		RTMlist1 = {},
		RTMlist2 = {},
		RTMlist3 = {},
		--WORLD
		WeatherCode = { Dependents = { 'WeatherCodeName', 'WeatherCodeLat', 'WeatherCodeLon' } },
		WeatherCodeName = {},
		WeatherCodeLat = {},
		WeatherCodeLon = {},
		Unit = { Loop = { 'c', 'f' },
			Labels = { 'Celsius', 'Fahrenheit' }
		},
		World1WeatherCode = { Dependents = { 'World1WeatherCodeName', 'World1WeatherCodeLat', 'World1WeatherCodeLon' } },
		World1WeatherCodeName = {},
		World1WeatherCodeLat = {},
		World1WeatherCodeLon = {},
		World2WeatherCode = { Dependents = { 'World2WeatherCodeName', 'World2WeatherCodeLat', 'World2WeatherCodeLon' } },
		World2WeatherCodeName = {},
		World2WeatherCodeLat = {},
		World2WeatherCodeLon = {},
		World3WeatherCode = { Dependents = { 'World3WeatherCodeName', 'World3WeatherCodeLat', 'World3WeatherCodeLon' } },
		World3WeatherCodeName = {},
		World3WeatherCodeLat = {},
		World3WeatherCodeLon = {},
		--APPS
		App1 = {},
		App1Path = { Flags = 'apppath',
			Dependents = { 'App1PathHandle' }
		},
		App1PathHandle = {},
		App1Label = {},
		App1Icon = {},
		App2 = {},
		App2Path = { Flags = 'apppath',
			Dependents = { 'App2PathHandle' }
		},
		App2PathHandle = {},
		App2Label = {},
		App2Icon = {},
		App3 = {},
		App3Path = { Flags = 'apppath',
			Dependents = { 'App3PathHandle' }
		},
		App3PathHandle = {},
		App3Label = {},
		App3Icon = {},
		App4 = {},
		App4Path = { Flags = 'apppath',
			Dependents = { 'App4PathHandle' }
		},
		App4PathHandle = {},
		App4Label = {},
		App4Icon = {},
		App5 = {},
		App5Path = { Flags = 'apppath',
			Dependents = { 'App5PathHandle' }
		},
		App5PathHandle = {},
		App5Label = {},
		App5Icon = {},
		--SEARCH
		Search1 = {},
		Search1Command = {},
		Search1Icon = {},
		Search2 = {},
		Search2Command = {},
		Search2Icon = {},
		Search3 = {},
		Search3Command = {},
		Search3Icon = {},
		Search4 = {},
		Search4Command = {},
		Search4Icon = {},
		Search5 = {},
		Search5Command = {},
		Search5Icon = {},
		--FORMAT
		Stylesheet = {},
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
			Loop = { '0', '1', '2' },
			Labels = { 'No', 'Yes', 'Double' }
		},
		SidebarAlpha = { File = StyleSettings },
		SidebarImage = { File = StyleSettings },
		SecondSidebarImage = { File = StyleSettings },
		TaskbarHeight = { File = StyleSettings },
		TaskbarSpacingFixed = { File = StyleSettings, 
			Loop = { '0', '1', '2' },
			Labels = { 'No', 'Yes', 'Double' }
		},
		TaskbarAlpha = { File = StyleSettings },
		TaskbarImage = { File = StyleSettings },
		SecondTaskbarImage = { File = StyleSettings },
		TaskbarMaxSkinWidth  = { File = StyleSettings },
		TaskbarMinSkinWidth  = { File = StyleSettings },
		TaskbarHideTriptych = { File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
		}
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
		local DependentValue = string.match(Value, '%.exe$') and string.match(Value, '([^/\\]+)$') or 'Rainmeter.exe'
		SKIN:Bang('!WriteKeyValue', 'Variables', DependentKey, DependentValue, Variables[DependentKey]['File'] or EnigmaSettings)
	end
	SKIN:Bang('!WriteKeyValue', 'Variables', Key, Value, Variables[Key]['File'] or EnigmaSettings)
	if not Wait then
		SKIN:Bang('!Refresh *')
	end
end

function Default(Key, Confirm)
	if Confirm == 1 then
		for _,v in ipairs(Variables[Key]['Dependents'] or {}) do
			Write(v, SKIN:GetVariable('Default'..v), 'wait')
		end
		Write(Key, SKIN:GetVariable('Default'..Key))
	else
		SKIN:Bang('!SetVariable', 'SelectedDefault', Key)
		SKIN:Bang('!ShowMeterGroup', 'Default')
		SKIN:Bang('!Redraw')
	end
end