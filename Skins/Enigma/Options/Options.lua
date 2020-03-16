function Initialize()
	-- SET LABELS FOR CURRENT TAB
	for Name in SELF:GetOption('LabelsQueue'):gmatch('[^%|]+') do
		local pos = TablePosition(Options[Name].Loop, SKIN:GetVariable(Name))
		SKIN:Bang('!SetOption', Name .. 'Text', 'Text', Options[Name].Labels[pos])
	end
end

function Write(Key, Value, Wait, SkipParse)
	-- IF NO VALUE IS GIVEN, ADVANCE BY LOOP
	if not Value then
		local pos = TablePosition(Options[Key].Loop, SKIN:GetVariable(Key))
		Value = Options[Key].Loop[(pos % #Options[Key].Loop) + 1]
	end

	-- WRITE
	SKIN:Bang('!WriteKeyValue', 'Variables', Key,
		(Options[Key].Parse and not SkipParse) and Options[Key].Parse(Key, Value) or Value,
		Options[Key].File and SKIN:GetVariable('StyleSettings') or SKIN:GetVariable('EnigmaSettings')
	)

	-- WAIT OR REFRESH
	if not Wait then
		-- if Options[Key].Configs then
		-- 	-- Because Enigma is fully portable, the root config name is not known.
		-- 	local RootConfig = SKIN:GetVariable('CURRENTCONFIG'):match('(.-\\)')
		-- 	for _, Config in ipairs(Options[Key].Configs) do
		-- 		SKIN:Bang('!Refresh', RootConfig .. Config)
		-- 	end
		--  SKIN:Bang('!Refresh')
		-- else
		-- 	SKIN:Bang('!Refresh *')
		-- end
		SKIN:Bang('!Refresh *')
	end
end

function TablePosition(tbl, key)
	for i, v in ipairs(tbl) do
		if v == key then
			return i
		end
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
		for _, DependentKey in ipairs(Options[Key].Dependents or {}) do
			Write(DependentKey, SKIN:GetVariable('Default' .. DependentKey), true, true)
		end

		-- RESET SELF
		Write(Key, SKIN:GetVariable('Default' .. Key), false, true)
	end
end

-----------------------------------------------------------------------
-- OPTION-SPECIFIC PARSING FUNCTIONS

function ParseProtocol(_, Value)
	return Value:match('://') and Value or 'http://' .. Value
end

function ParseGmail(_, Value)
	local id, domain = Value:match('^([^@]+)@?(.*)')
	if domain == '' then domain = 'gmail.com' end -- No domain was given.
	if domain == 'gmail.com' then
		Write('GmailUrl', 'https://[#*GmailUsername*]:[#*GmailPassword*]@gmail.google.com/gmail/feed/atom', true)
	else
		Write('GmailUrl', 'https://[#*GmailUsername*]%40[#*GmailDomain*]:[#*GmailPassword*]@mail.google.com/a/[#*GmailDomain*]/feed/atom/', true)
	end
	Write('GmailDomain', domain, true)
	return id
end

function ParseGcal(_, Value)
	return ParseProtocol(_, Value):gsub('/basic', '/full')
end

function ParseAppPath(Key, Value)
	Write(Options[Key].Dependents[1], Value:match('%.exe$') and Value:match('([^/\\]+)$') or 'Rainmeter.exe', true)
	return Value
end

function urlEncode(str)
	local encode = function(input)
		return string.format("%%%02X", input:byte())
	end
	
	if str then
		return (str:gsub("\n", "\r\n"):gsub("([^%w ])", encode):gsub(" ", "+"))
	end
	return str
 end
 
 function ParsePassword(_, Value)
 	return urlEncode(Value)
 end

-----------------------------------------------------------------------
-- MASTER TABLE
-- The Options table defines value loops, display labels, target configs, etc. for all Enigma options.

Options = {
	-- GENERAL
	Note1Path = {Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes1' },},
	Note2Path = {Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes2' },},
	Note3Path = {Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes3' },},
	NoteHeight = {Configs = { 'Sidebar\\Notes', 'Sidebar\\Notes\\Notes1', 'Sidebar\\Notes\\Notes2', 'Sidebar\\Notes\\Notes3' },},
	Drive1 = {Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive1' },},
	Drive2 = {Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive2' },},
	Drive3 = {Configs = { 'Sidebar\\System', 'Taskbar\\System', 'Taskbar\\System\\Drive\\Drive3' },},
	NetworkMaxDownload = {Configs = { 'Sidebar\\Network', 'Taskbar\\Network', 'Taskbar\\Network\\Download' },},
	NetworkMaxUpload = {Configs = { 'Sidebar\\Network', 'Taskbar\\Network', 'Taskbar\\Network\\Upload' },},
	SystemGraphType = {
		Configs = { 'Sidebar\\Network', 'Sidebar\\System' },
		Loop    = { 'Floating', 'Percent' }
	},
	CalendarEventFile = {Configs = { 'Sidebar\\Calendar' },},
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
	GalleryPath = {Configs = { 'Sidebar\\Gallery' },},
	GallerySubfolders = { 
		Configs = { 'Sidebar\\Gallery' },
		Loop    = { '0', '1' },
		Labels  = { 'No', 'Yes' }
	},
	GalleryRatio = {Configs = { 'Sidebar\\Gallery' },},
	GalleryPosition = { 
		Configs = { 'Sidebar\\Gallery' },
		Loop    = { 'Center', 'Tile', 'Stretch', 'Fit', 'Fill' }
	},
	VolumeIncrement = {Configs = { 'Sidebar\\Volume', 'Taskbar\\Volume' },},
	TriptychInterval = {Configs = { 'Sidebar\\Gallery', 'Sidebar\\Notes', 'Sidebar\\Reader', 'Sidebar\\Reader\\Gcal', 'Sidebar\\Reader\\RememberTheMilk' },},
	TriptychDisabled = { 
		Configs = { 'Sidebar\\Gallery', 'Sidebar\\Notes', 'Sidebar\\Reader', 'Sidebar\\Reader\\Gcal', 'Sidebar\\Reader\\RememberTheMilk' },
		Loop    = { '0', '1' },
		Labels  = { 'Yes', 'No' }
	},
	ProcessInterval = {Configs = { 'Sidebar\\Process' },},
	-- MUSIC
	MusicPlayerType = {Configs = { 'Sidebar\\Music', 'Taskbar\\Music' },},
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
		Parse   = ParseGmail,
		Dependents = {'GmailPassword', 'GmailUrl', 'GmailDomain'}
	},
	GmailPassword = {
		Configs = { 'Sidebar\\Reader\\Gmail', 'Taskbar\\Reader\\Gmail' },
		Parse = ParsePassword,
	},
	GmailUrl = {},
	GmailDomain = {},
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
	RTMusername = {Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' },},
	RTMpassword = {Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' },},
	RTMlist1 = {Configs = { 'Sidebar\\Reader\\RememberTheMilk', 'Taskbar\\Reader\\RememberTheMilk' },},
	RTMlist2 = {Configs = { 'Sidebar\\Reader\\RememberTheMilk' },},
	RTMlist3 = {Configs = { 'Sidebar\\Reader\\RememberTheMilk' },},
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
	App1 = {Configs = { 'Taskbar\\Launcher\\Launcher1' },},
	App1Path = {
		Dependents = { 'App1PathHandle' },
		Configs    = { 'Taskbar\\Launcher\\Launcher1' },
		Parse      = ParseAppPath
	},
	App1PathHandle = {},
	App1Label = {Configs = { 'Taskbar\\Launcher\\Launcher1' },},
	App1Icon = {Configs = { 'Taskbar\\Launcher\\Launcher1' },},
	App2 = {Configs = { 'Taskbar\\Launcher\\Launcher2' },},
	App2Path = {
		Dependents = { 'App2PathHandle' },
		Configs    = { 'Taskbar\\Launcher\\Launcher2' },
		Parse      = ParseAppPath
	},
	App2PathHandle = {},
	App2Label = {Configs = { 'Taskbar\\Launcher\\Launcher2' },},
	App2Icon = {Configs = { 'Taskbar\\Launcher\\Launcher2' },},
	App3 = {Configs = { 'Taskbar\\Launcher\\Launcher3' },},
	App3Path = {
		Dependents = { 'App3PathHandle' },
		Configs    = { 'Taskbar\\Launcher\\Launcher3' },
		Parse      = ParseAppPath
	},
	App3PathHandle = {},
	App3Label = {Configs = { 'Taskbar\\Launcher\\Launcher3' },},
	App3Icon = {Configs = { 'Taskbar\\Launcher\\Launcher3' },},
	App4 = {Configs = { 'Taskbar\\Launcher\\Launcher4' },},
	App4Path = {
		Dependents = { 'App4PathHandle' },
		Configs    = { 'Taskbar\\Launcher\\Launcher4' },
		Parse      = ParseAppPath
	},
	App4PathHandle = {},
	App4Label = {Configs = { 'Taskbar\\Launcher\\Launcher4' },},
	App4Icon = {Configs = { 'Taskbar\\Launcher\\Launcher4' },},
	App5 = {Configs = { 'Taskbar\\Launcher\\Launcher5' },},
	App5Path = {
		Dependents = { 'App5PathHandle' },
		Configs    = { 'Taskbar\\Launcher\\Launcher5' },
		Parse      = ParseAppPath
	},
	App5PathHandle = {},
	App5Label = {Configs = { 'Taskbar\\Launcher\\Launcher5' },},
	App5Icon = {Configs = { 'Taskbar\\Launcher\\Launcher5' },},
	-- SEARCH
	Search1 = {Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' },},
	Search1Command = {
		Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' },
		Parse   = ParseProtocol
	},
	Search1Icon = {Configs = { 'Taskbar\\Search\\Search1', 'Taskbar\\Search\\Run' },},
	Search2 = {Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' },},
	Search2Command = {
		Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' },
		Parse   = ParseProtocol
	},
	Search2Icon = {Configs = { 'Taskbar\\Search\\Search2', 'Taskbar\\Search\\Run' },},
	Search3 = {Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' },},
	Search3Command = {
		Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' },
		Parse   = ParseProtocol
	},
	Search3Icon = {Configs = { 'Taskbar\\Search\\Search3', 'Taskbar\\Search\\Run' },},
	Search4 = {Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' },},
	Search4Command = {
		Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' },
		Parse   = ParseProtocol
	},
	Search4Icon = {Configs = { 'Taskbar\\Search\\Search4', 'Taskbar\\Search\\Run' },},
	Search5 = {Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' },},
	Search5Command = {
		Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' },
		Parse   = ParseProtocol
	},
	Search5Icon = {Configs = { 'Taskbar\\Search\\Search5', 'Taskbar\\Search\\Run' },},
	-- FORMAT
	Stylesheet = {},
	Color1 = {File = true},
	ColorLink = {File = true},
	ColorBorder = {File = true},
	ColorEvent = {File = true},
	ColorPanel = {File = true},
	ColorFilter = {File = true},
	ColorTransparent = {File = true},
	ColorImage = {
		File = true,
		Loop = { 'W', 'B' },
		Labels = { 'W', 'B' }
	},
	Size1 = {File = true},
	Size4 = {File = true},
	Size3 = {File = true},
	Size2 = {File = true},
	Font = {File = true},
	SkinBackgroundAlpha  = {File = true},
	HideBordersTop = {
		File = true, 
		Loop = { '0', '1' },
		Labels = { 'Yes', 'No' }
	},
	HideBordersBottom = {
		File = true, 
		Loop = { '0', '1' },
		Labels = { 'Yes', 'No' }
	},
	--LAYOUT
	SidebarWidth = {File = true},
	SidebarSpacingFixed = {
		File = true,
		Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }, 
		Loop = { '0', '1', '2' },
		Labels = { 'No', 'Yes', 'Double' }
	},
	SidebarAlpha = {
		File = true,
		Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
	},
	SidebarImage = {
		File = true,
		Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
	},
	SecondSidebarImage = {
		File = true,
		Configs = { 'Sidebar', 'Sidebar\\Sidebar2' }
	},
	TaskbarHeight = {File = true},
	TaskbarSpacingFixed = {
		File = true, 
		Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
		Loop = { '0', '1', '2' },
		Labels = { 'No', 'Yes', 'Double' }
	},
	TaskbarAlpha = {
		File = true,
		Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
	},
	TaskbarImage = {
		File = true,
		Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
	},
	SecondTaskbarImage = {
		File = true,
		Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
	},
	TaskbarMaxSkinWidth  = {File = true},
	TaskbarMinSkinWidth  = {File = true},
	TaskbarHideTriptych = {
		File = true,
		Configs = { 'Taskbar', 'Taskbar\\Taskbar2' },
		Loop = { '0', '1' },
		Labels = { 'Yes', 'No' }
	}
}