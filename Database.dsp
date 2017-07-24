# Microsoft Developer Studio Project File - Name="Database" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Database - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Database.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Database.mak" CFG="Database - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Database - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Database - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Database - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Database - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Database - Win32 Release"
# Name "Database - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AcademicEducationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AcademicEducationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AddBaseInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AdministrativePostDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AdministrativePostSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AppendantDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AppendantSet.cpp
# End Source File
# Begin Source File

SOURCE=.\AuxiliaryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AuxiliarySet.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseArchiveDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BrowseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassTeachingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ClassTeachingSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ContactsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ContactsSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Container.cpp
# End Source File
# Begin Source File

SOURCE=.\ContinueEducationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ContinueEducationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\Database.cpp
# End Source File
# Begin Source File

SOURCE=.\Database.rc
# End Source File
# Begin Source File

SOURCE=.\DatabaseDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\DatabaseView.cpp
# End Source File
# Begin Source File

SOURCE=.\DepartmentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DepartmentSectionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DepartmentSectionSet.cpp
# End Source File
# Begin Source File

SOURCE=.\DepartmentSet.cpp
# End Source File
# Begin Source File

SOURCE=.\DisciplinePunishDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DisciplinePunishSet.cpp
# End Source File
# Begin Source File

SOURCE=.\EducationDegreeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EducationDegreeSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FamilyMemberDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FamilyMemberSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FulltimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FulltimeSet.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MeetingRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MeetingRecordSet.cpp
# End Source File
# Begin Source File

SOURCE=.\NationInformationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NationInformationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\NewCThinDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NotesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NotesSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PaperDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PaperSet1.cpp
# End Source File
# Begin Source File

SOURCE=.\PoliticalStatusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PoliticalStatusSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PositionInformationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PositionInformationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjectSet.cpp
# End Source File
# Begin Source File

SOURCE=.\RewardRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RewardRecordSet.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SectionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SectionSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StaffSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TechnicalAccessDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TechnicalAccessSet.cpp
# End Source File
# Begin Source File

SOURCE=.\TechnicalPostDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TechnicalPostSet.cpp
# End Source File
# Begin Source File

SOURCE=.\User.cpp
# End Source File
# Begin Source File

SOURCE=.\UserSettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WageLevelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WageLevelSet.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkExperienceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkExperienceSet.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AcademicEducationDlg.h
# End Source File
# Begin Source File

SOURCE=.\AcademicEducationSet.h
# End Source File
# Begin Source File

SOURCE=.\AddBaseInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\AdministrativePostDlg.h
# End Source File
# Begin Source File

SOURCE=.\AdministrativePostSet.h
# End Source File
# Begin Source File

SOURCE=.\AppendantDlg.h
# End Source File
# Begin Source File

SOURCE=.\AppendantSet.h
# End Source File
# Begin Source File

SOURCE=.\AuxiliaryDlg.h
# End Source File
# Begin Source File

SOURCE=.\AuxiliarySet.h
# End Source File
# Begin Source File

SOURCE=.\BaseArchiveDlg.h
# End Source File
# Begin Source File

SOURCE=.\BrowseDlg.h
# End Source File
# Begin Source File

SOURCE=.\ClassTeachingDlg.h
# End Source File
# Begin Source File

SOURCE=.\ClassTeachingSet.h
# End Source File
# Begin Source File

SOURCE=.\ContactsDlg.h
# End Source File
# Begin Source File

SOURCE=.\ContactsSet.h
# End Source File
# Begin Source File

SOURCE=.\Container.h
# End Source File
# Begin Source File

SOURCE=.\ContinueEducationDlg.h
# End Source File
# Begin Source File

SOURCE=.\ContinueEducationSet.h
# End Source File
# Begin Source File

SOURCE=.\Database.h
# End Source File
# Begin Source File

SOURCE=.\DatabaseDoc.h
# End Source File
# Begin Source File

SOURCE=.\DatabaseView.h
# End Source File
# Begin Source File

SOURCE=.\DepartmentDlg.h
# End Source File
# Begin Source File

SOURCE=.\DepartmentSectionDlg.h
# End Source File
# Begin Source File

SOURCE=.\DepartmentSectionSet.h
# End Source File
# Begin Source File

SOURCE=.\DepartmentSet.h
# End Source File
# Begin Source File

SOURCE=.\DisciplinePunishDlg.h
# End Source File
# Begin Source File

SOURCE=.\DisciplinePunishSet.h
# End Source File
# Begin Source File

SOURCE=.\EducationDegreeDlg.h
# End Source File
# Begin Source File

SOURCE=.\EducationDegreeSet.h
# End Source File
# Begin Source File

SOURCE=.\FamilyMemberDlg.h
# End Source File
# Begin Source File

SOURCE=.\FamilyMemberSet.h
# End Source File
# Begin Source File

SOURCE=.\FulltimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\FulltimeSet.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MeetingRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\MeetingRecordSet.h
# End Source File
# Begin Source File

SOURCE=.\NationInformationDlg.h
# End Source File
# Begin Source File

SOURCE=.\NationInformationSet.h
# End Source File
# Begin Source File

SOURCE=.\NewCThinDlg.h
# End Source File
# Begin Source File

SOURCE=.\NotesDlg.h
# End Source File
# Begin Source File

SOURCE=.\NotesSet.h
# End Source File
# Begin Source File

SOURCE=.\PaperDlg.h
# End Source File
# Begin Source File

SOURCE=.\PaperSet1.h
# End Source File
# Begin Source File

SOURCE=.\PoliticalStatusDlg.h
# End Source File
# Begin Source File

SOURCE=.\PoliticalStatusSet.h
# End Source File
# Begin Source File

SOURCE=.\PositionInformationDlg.h
# End Source File
# Begin Source File

SOURCE=.\PositionInformationSet.h
# End Source File
# Begin Source File

SOURCE=.\ProjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\ProjectSet.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RewardRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\RewardRecordSet.h
# End Source File
# Begin Source File

SOURCE=.\SearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\SectionDlg.h
# End Source File
# Begin Source File

SOURCE=.\SectionSet.h
# End Source File
# Begin Source File

SOURCE=.\StaffSet.h
# End Source File
# Begin Source File

SOURCE=.\StatisticsDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalAccessDlg.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalAccessSet.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalPostDlg.h
# End Source File
# Begin Source File

SOURCE=.\TechnicalPostSet.h
# End Source File
# Begin Source File

SOURCE=.\User.h
# End Source File
# Begin Source File

SOURCE=.\UserSettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\WageLevelDlg.h
# End Source File
# Begin Source File

SOURCE=.\WageLevelSet.h
# End Source File
# Begin Source File

SOURCE=.\WorkExperienceDlg.h
# End Source File
# Begin Source File

SOURCE=.\WorkExperienceSet.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Database.ico
# End Source File
# Begin Source File

SOURCE=.\res\Database.rc2
# End Source File
# Begin Source File

SOURCE=.\res\DatabaseDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\login.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainFrame.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
