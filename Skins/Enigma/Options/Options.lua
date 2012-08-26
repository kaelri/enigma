function Initialize()
	EnigmaSettings          = SKIN:GetVariable('EnigmaSettings')
	StyleSettings           = SKIN:GetVariable('StyleSettings')

	-- GET ROOT CONFIG
	-- Because Enigma is fully portable, the root config name is not known.
	local CurrentConfig     = SKIN:GetVariable('CURRENTCONFIG')
	RootConfig              = string.match(CurrentConfig, '(.-\\)')
	
	-- CREATE MASTER TABLE
	-- The Options table defines value loops, display labels, target configs, etc. for all Enigma options.
	DefineOptions()
	
	-- SET LABELS FOR CURRENT TAB
	for Name in string.gmatch(SELF:GetOption('LabelsQueue'),'[^%|]+') do
		local Loop   = Options[Name].Loop
		local Labels = Options[Name].Labels
		for i, v in ipairs(Loop) do
			if v == SKIN:GetVariable(Name) then
				SKIN:Bang('!SetOption', Name..'Text', 'Text', Labels[i])
				break
			end
		end
	end
	
end

function Write(Key, Value, Wait)
	local Option = Options[Key]

	-- IF NO VALUE IS GIVEN, ADVANCE BY LOOP
	if not Value then
		local Loop = Option.Loop
		for i, v in ipairs(Loop) do
			if v == SKIN:GetVariable(Key) then
				Value = Loop[(i % #Loop) + 1]
				break
			end
		end
	end

	-- APPLY OPTION-SPECIFIC PARSING
	if Option.Parse then
		Value = Option.Parse(Key, Value)
	end

	-- WRITE
	local File = Option.File or EnigmaSettings
	SKIN:Bang('!WriteKeyValue', 'Variables', Key, Value, File)

	-- WAIT OR REFRESH
	if not Wait then
		-- if Option.Configs then
		-- 	for _, Config in ipairs(Option.Configs) do
		-- 		SKIN:Bang('!Refresh', RootConfig..Config)
		-- 	end
		-- 	SKIN:Bang('!Refresh')
		-- else
		-- 	SKIN:Bang('!Refresh *')
		-- end
		SKIN:Bang('!Refresh *')
	end
end

function Default(Key, Confirm)
	if not Confirm then
		-- PROMPT CONFIRMATION
		SKIN:Bang('!SetVariable', 'SelectedDefault', Key)
		SKIN:Bang('!UpdateMeterGroup', 'Default')
		SKIN:Bang('!ShowMeterGroup', 'Default')
		SKIN:Bang('!Redraw')
	else
		-- RESET DEPENDENTS
		local Dependents = Options[Key].Dependents or {}
		for _, DependentKey in ipairs(Dependents) do
			local DependentValue = SKIN:GetVariable('Default'..DependentKey)
			Write(DependentKey, DependentValue, true)
		end

		-- RESET SELF
		Write(Key, SKIN:GetVariable('Default'..Key))
	end
end

-----------------------------------------------------------------------
-- OPTION-SPECIFIC PARSING FUNCTIONS

function ParseProtocol(_, Value)
	return string.match(Value, '://') and Value or 'http://'..Value
end

function ParseGmail(_, Value)
	return string.gsub(Value, '@gmail.com', '')
end

function ParseGcal(_, Value)
	Value = ParseProtocol(_, Value)
	return string.gsub(Value, '/basic', '/full')
end

function ParseAppPath(Key, Value)
	local DependentKey   = Options[Key].Dependents[1]
	local DependentValue = string.match(Value, '%.exe$') and string.match(Value, '([^/\\]+)$') or 'Rainmeter.exe'
	Write(DependentKey, DependentValue, true)
	return Value
end

-----------------------------------------------------------------------
-- MASTER TABLE

function DefineOptions()
	Options = {
		-- GENERAL
		Note1Path = {
			Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes1' }
			},
		Note2Path = {
			Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes2' }
			},
		Note3Path = {
			Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes3' }
			},
		NoteHeight = {
			Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes1', 'Sidebar\\Notes\\Notes2', 'Sidebar\\Notes\\Notes3' }
			},
		Drive1 = {
			Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive1' }
			},
		Drive2 = {
			Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive2' }
			},
		Drive3 = {
			Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive3' }
			},
		NetworkMaxDownload = {
			Configs = { 'Sidebar\\Network', 'Taskbar\\Network', 'Taskbar\\Network\\Download' }
			},
		NetworkMaxUpload = {
			Configs = { 'Sidebar\\Network', 'Taskbar\\Network', 'Taskbar\\Network\\Upload' }
			},
		SystemGraphType = {
			Configs = { 'Sidebar\\Network', 'Sidebar\\System' },
			Loop    = { 'Floating', 'Percent' }
			},
		CalendarEventFile = {
			Configs = { 'Sidebar\\Calendar' }
			},
		CalendarShowEvents = {
			Configs = { 'Sidebar\\Calendar' },
			Loop    = { '0', '1' },
			Labels  = { 'No', 'Yes' }
			},
		CalendarExtraDays = {
			Configs = { 'Sidebar\\Calendar' },
			Loop    = { '0', '1' },
			Labels  = { 'No', 'Yes' }
			},
		CalendarLeadingZeroes = {
			Configs = { 'Sidebar\\Calendar' },
			Loop    = { '0', '1' },
			Labels  = { 'No', 'Yes' }
			},
		CalendarMondays = {
			Configs = { 'Sidebar\\Calendar' },
			Loop    = { '0', '1' },
			Labels  = { 'Sunday', 'Monday' }
			},
		GalleryPath = {
			Configs = { 'Sidebar\\Gallery' }
			},
		GallerySubfolders = { 
			Configs = { 'Sidebar\\Gallery' },
			Loop    = { '0', '1' },
			Labels  = { 'No', 'Yes' }
			},
		GalleryRatio = {
			Configs = { 'Sidebar\\Gallery' }
			},
		GalleryPosition = { 
			Configs = { 'Sidebar\\Gallery' },
			Loop    = { 'Center', 'Tile', 'Stretch', 'Fit', 'Fill' }
			},
		VolumeIncrement = {
			Configs = { 'Sidebar\\Volume', 'Taskbar\\Volume' }
			},
		TriptychInterval = {
			Configs = { 'Sidebar\\Gallery', 'Sidebar\\Notes', 'Sidebar\\Reader', 'Sidebar\\Reader\\Gcal', 'Sidebar\\Reader\\RememberTheMilk' }
			},
		TriptychDisabled = { 
			Configs = { 'Sidebar\\Gallery', 'Sidebar\\Notes', 'Sidebar\\Reader', 'Sidebar\\Reader\\Gcal', 'Sidebar\\Reader\\RememberTheMilk' },
			Loop    = { '0', '1' },
			Labels  = { 'Yes', 'No' }
			},
		ProcessInterval = {
			Configs = { 'Sidebar\\Process' }
			},

		-- MUSIC
		MusicPlayerType = {
			Configs = { 'Sidebar\\Music', 'Taskbar\\Music' }
			},
		MusicPlayer = {},

		--FEEDS
		Feed1 = {
			Configs = { 'Sidebar\\Reader', 'Sidebar\\Reader\\Reader1' },
			Parse   = ParseProtocol
			},
		Feed2 = {
			Configs = { 'Sidebar\\Reader', 'Sidebar\\Reader\\Reader2' },
			Parse   = ParseProtocol
			},
		Feed3 = {
			Configs = { 'Sidebar\\Reader', 'Sidebar\\Reader\\Reader3' },
			Parse   = ParseProtocol
			},
		GmailUsername = {
			Configs = { 'Sidebar\\Reader\\Gmail', 'Taskbar\\Reader\\Gmail' },
			Parse   = ParseGmail
			},
		GmailPassword = {
			Configs = { 'Sidebar\\Reader\\Gmail', 'Taskbar\\Reader\\Gmail' },
			},
		FacebookFeed = {
			Configs = { 'Sidebar\\Reader\\Facebook', 'Taskbar\\Reader\\Facebook' },
			Parse   = ParseProtocol
			},
		GoogleCalendar1 = {
			Configs = { 'Sidebar\\Reader\\Gcal', 'Taskbar\\Reader\\Gcal' },
			Parse   = ParseGcal
			},
		GoogleCalendar2 = {
			Configs = { 'Sidebar\\Reader\\Gcal' },
			Parse   = ParseGcal
			},
		GoogleCalendar3 = {
			Configs = { 'Sidebar\\Reader\\Gcal' },
			Parse   = ParseGcal
			},
		GoogleCalendarWriteEvents = {
			Configs = { 'Sidebar\\Reader\\Gcal', 'Taskbar\\Reader\\Gcal' },
			Loop    = { '0', '1' },
			Labels  = { 'No', 'Yes' }
			},
		RTMusername = {
			Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' }
			},
		RTMpassword = {
			Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' }
			},
		RTMlist1 = {
			Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' }
			},
		RTMlist2 = {
			Configs = { 'Sidebar\\Reader\\RememberTheMilk' }
			},
		RTMlist3 = {
			Configs = { 'Sidebar\\Reader\\RememberTheMilk' }
			},

		-- WORLD
		WeatherCode = {
			Dependents = { 'WeatherCodeName', 'WeatherCodeLat', 'WeatherCodeLon' },
			Configs    = {
				'Sidebar\\Clock',
				'Sidebar\\Weather',
				'Taskbar\\Weather',
				'Taskbar\\Weather\\Location',
				'Taskbar\\Weather\\Sunrise',
				'Taskbar\\Weather\\Sunset',
				'Taskbar\\Weather\\WeatherToday',
				'Taskbar\\Weather\\WeatherTomorrow',
				'Taskbar\\_Extras\\Clock+Location',
				'Taskbar\\_Extras\\TrayClock'
				}
			},
		WeatherCodeName = {},
		WeatherCodeLat = {},
		WeatherCodeLon = {},
		Unit = { 
			Configs = {
				'Sidebar\\Clock',
				'Sidebar\\Weather',
				'Sidebar\\World\\World1',
				'Sidebar\\World\\World2',
				'Sidebar\\World\\World3',
				'Taskbar\\Weather',
				'Taskbar\\Weather\\Location',
				'Taskbar\\Weather\\Sunrise',
				'Taskbar\\Weather\\Sunset',
				'Taskbar\\Weather\\WeatherToday',
				'Taskbar\\Weather\\WeatherTomorrow',
				'Taskbar\\World\\World1',
				'Taskbar\\World\\World2',
				'Taskbar\\World\\World3',
				'Taskbar\\_Extras\\Clock+Location',
				'Taskbar\\_Extras\\TrayClock'
				},
			Loop    = { 'c', 'f' },
			Labels  = { 'Celsius', 'Fahrenheit' }
			},
		World1WeatherCode = {
			Dependents = { 'World1WeatherCodeName', 'World1WeatherCodeLat', 'World1WeatherCodeLon' },
			Configs    = { 'Sidebar\\World\\World1', 'Taskbar\\World\\World1' }
			},
		World1WeatherCodeName = {},
		World1WeatherCodeLat = {},
		World1WeatherCodeLon = {},
		World2WeatherCode = {
			Dependents = { 'World2WeatherCodeName', 'World2WeatherCodeLat', 'World2WeatherCodeLon' },
			Configs    = { 'Sidebar\\World\\World2', 'Taskbar\\World\\World2' }
			},
		World2WeatherCodeName = {},
		World2WeatherCodeLat = {},
		World2WeatherCodeLon = {},
		World3WeatherCode = {
			Dependents = { 'World3WeatherCodeName', 'World3WeatherCodeLat', 'World3WeatherCodeLon' },
			Configs    = {}
			},
		World3WeatherCodeName = {},
		World3WeatherCodeLat = {},
		World3WeatherCodeLon = {},

		-- APPS
		App1 = {
			Configs = { 'Taskbar\\Launcher\\Launcher1' }
			},
		App1Path = {
			Dependents = { 'App1PathHandle' },
			Configs    = { 'Taskbar\\Launcher\\Launcher1' },
			Parse      = ParseAppPath
			},
		App1PathHandle = {},
		App1Label = {
			Configs = { 'Taskbar\\Launcher\\Launcher1' }
			},
		App1Icon = {
			Configs = { 'Taskbar\\Launcher\\Launcher1' }
			},
		App2 = {
			Configs = { 'Taskbar\\Launcher\\Launcher2' }
			},
		App2Path = {
			Dependents = { 'App2PathHandle' },
			Configs    = { 'Taskbar\\Launcher\\Launcher2' },
			Parse      = ParseAppPath
			},
		App2PathHandle = {},
		App2Label = {
			Configs = { 'Taskbar\\Launcher\\Launcher2' }
			},
		App2Icon = {
			Configs = { 'Taskbar\\Launcher\\Launcher2' }
			},
		App3 = {
			Configs = { 'Taskbar\\Launcher\\Launcher3' }
			},
		App3Path = {
			Dependents = { 'App3PathHandle' },
			Configs    = { 'Taskbar\\Launcher\\Launcher3' },
			Parse      = ParseAppPath
			},
		App3PathHandle = {},
		App3Label = {
			Configs = { 'Taskbar\\Launcher\\Launcher3' }
			},
		App3Icon = {
			Configs = { 'Taskbar\\Launcher\\Launcher3' }
			},
		App4 = {
			Configs = { 'Taskbar\\Launcher\\Launcher4' }
			},
		App4Path = {
			Dependents = { 'App4PathHandle' },
			Configs    = { 'Taskbar\\Launcher\\Launcher4' },
			Parse      = ParseAppPath
			},
		App4PathHandle = {},
		App4Label = {
			Configs = { 'Taskbar\\Launcher\\Launcher4' }
			},
		App4Icon = {
			Configs = { 'Taskbar\\Launcher\\Launcher4' }
			},
		App5 = {
			Configs = { 'Taskbar\\Launcher\\Launcher5' }
			},
		App5Path = {
			Dependents = { 'App5PathHandle' },
			Configs    = { 'Taskbar\\Launcher\\Launcher5' },
			Parse      = ParseAppPath
			},
		App5PathHandle = {},
		App5Label = {
			Configs = { 'Taskbar\\Launcher\\Launcher5' }
			},
		App5Icon = {
			Configs = { 'Taskbar\\Launcher\\Launcher5' }
			},

		-- SEARCH
		Search1 = {
			Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' }
			},
		Search1Command = {
			Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' },
			Parse   = ParseProtocol
			},
		Search1Icon = {
			Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' }
			},
		Search2 = {
			Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' }
			},
		Search2Command = {
			Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' },
			Parse   = ParseProtocol
			},
		Search2Icon = {
			Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' }
			},
		Search3 = {
			Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' }
			},
		Search3Command = {
			Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' },
			Parse   = ParseProtocol
			},
		Search3Icon = {
			Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' }
			},
		Search4 = {
			Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' }
			},
		Search4Command = {
			Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' },
			Parse   = ParseProtocol
			},
		Search4Icon = {
			Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' }
			},
		Search5 = {
			Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' }
			},
		Search5Command = {
			Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' },
			Parse   = ParseProtocol
			},
		Search5Icon = {
			Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' }
			},

		-- FORMAT
		Stylesheet = {},
		Color1 = {
			File = StyleSettings
			},
		ColorLink = {
			File = StyleSettings
			},
		ColorBorder = {
			File = StyleSettings
			},
		ColorEvent = {
			File = StyleSettings
			},
		ColorPanel = {
			File = StyleSettings
			},
		ColorFilter = {
			File = StyleSettings
			},
		ColorTransparent = {
			File = StyleSettings
			},
		ColorImage = {
			File = StyleSettings,
			Loop = { 'W', 'B' },
			Labels = { 'W', 'B' }
			},
		Size1 = {
			File = StyleSettings
			},
		Size4 = {
			File = StyleSettings
			},
		Size3 = {
			File = StyleSettings
			},
		Size2 = {
			File = StyleSettings
			},
		Font = {
			File = StyleSettings
			},
		SkinBackgroundAlpha  = {
			File = StyleSettings
			},
		HideBordersTop = {
			File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
			},
		HideBordersBottom = {
			File = StyleSettings, 
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
			},
		--LAYOUT
		SidebarWidth = {
			File = StyleSettings
			},
		SidebarSpacingFixed = {
			File = StyleSettings,
			Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }, 
			Loop = { '0', '1', '2' },
			Labels = { 'No', 'Yes', 'Double' }
			},
		SidebarAlpha = {
			File = StyleSettings,
			Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
			},
		SidebarImage = {
			File = StyleSettings,
			Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
			},
		SecondSidebarImage = {
			File = StyleSettings,
			Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
			},
		TaskbarHeight = {
			File = StyleSettings
			},
		TaskbarSpacingFixed = {
			File = StyleSettings, 
			Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
			Loop = { '0', '1', '2' },
			Labels = { 'No', 'Yes', 'Double' }
			},
		TaskbarAlpha = {
			File = StyleSettings,
			Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
			},
		TaskbarImage = {
			File = StyleSettings,
			Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
			},
		SecondTaskbarImage = {
			File = StyleSettings,
			Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
			},
		TaskbarMaxSkinWidth  = {
			File = StyleSettings
			},
		TaskbarMinSkinWidth  = {
			File = StyleSettings
			},
		TaskbarHideTriptych = {
			File = StyleSettings, 
			Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
			Loop = { '0', '1' },
			Labels = { 'Yes', 'No' }
			}
		}
end