; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Database.h"
LastPage=0

ClassCount=68
Class1=CDatabaseApp
Class2=CDatabaseDoc
Class3=CDatabaseView
Class4=CMainFrame

ResourceCount=37
Resource1=IDD_DIALOG_DEPARTMENT
Resource2=IDR_MENU1
Class5=CAboutDlg
Resource3=IDD_DIALOG_AUXILIARY
Class6=CUser
Class7=CLoginDlg
Resource4=IDD_DIALOG_ADMINISTRATIVEPOST
Class8=CUserSettingDlg
Resource5=IDD_DIALOG_HREWARDRECORD
Class9=CAddBaseInfoDlg
Class10=CNationInformationSet
Resource6=IDD_DIALOG_NOTES
Class11=CNationInformationDlg
Resource7=IDD_DIALOG_HFAMILYMEMBER
Class12=CPositionInformationSet
Class13=CPositionInformationDlg
Resource8=IDR_MAINFRAME
Class14=CEducationDegreeSet
Class15=CEducationDegreeDlg
Resource9=IDD_DIALOG_LOGIN
Class16=CPoliticalStatusSet
Class17=CPoliticalStatusDlg
Resource10=IDD_DIALOG_COMMON
Class18=CDepartmentSectionSet
Class19=CDepartmentSectionDlg
Resource11=IDD_DIALOG_WAGELEVEL
Class20=CWageLevelSet
Class21=CWageLevelDlg
Resource12=IDD_DIALOG_TECHNICALPOST
Class22=CTechnicalPostSet
Class23=CTechnicalPostDlg
Resource13=IDD_DIALOG_NEWCTHIN
Class24=CAdministrativePostSet
Class25=CAdministrativePostDlg
Resource14=IDD_DIALOG_BROWSE
Class26=CDepartmentSet
Class27=CDepartmentDlg
Resource15=IDD_DIALOG_HSEARCH
Class28=CSectionSet
Class29=CSectionDlg
Class30=CAuxiliarySet
Resource16=IDD_DIALOG_HPROJECT
Class31=CAuxiliaryDlg
Resource17=IDD_ABOUTBOX
Class32=CAppendantSet
Class33=CAppendantDlg
Resource18=IDD_DIALOG_HCONTINUEEDUCATION
Class34=CFulltimeSet
Class35=CFulltimeDlg
Resource19=IDD_DIALOG_FULLTIME
Class36=CBaseArchiveDlg
Class37=CStaffSet
Resource20=IDD_DIALOG_SECTION
Class38=CFamilyMemberSet
Class39=CFamilyMemberDlg
Class40=CWorkExperienceSet
Resource21=IDD_DIALOG_APPENDANT
Class41=CWorkExperienceDlg
Resource22=IDD_DIALOG_HPAPER
Class42=CRewardRecordSet
Class43=CRewardRecordDlg
Resource23=IDD_DIALOG_POLITICALSTATUS
Class44=CDisciplinePunishSet
Class45=CDisciplinePunishDlg
Resource24=IDD_HUMAN_HBASEARCHIVE
Class46=CPaperSet1
Class47=CPaperDlg
Resource25=IDD_DIALOG_HCLASSTEACHING
Class48=CProjectSet
Class49=CProjectDlg
Class50=CTechnicalAccessSet
Resource26=IDD_DIALOG_HTECHNICALACCESS
Class51=CTechnicalAccessDlg
Resource27=IDD_DIALOG_COMMUNICATIONTHIN
Class52=CAcademicEducationSet
Class53=CAcademicEducationDlg
Resource28=IDD_DIALOG_HWORKEXPERIENCE
Class54=CContinueEducationSet
Class55=CContinueEducationDlg
Resource29=IDD_DIALOG_USERSETTING
Class56=CClassTeachingSet
Class57=CClassTeachingDlg
Class58=CContainer
Resource30=IDD_DIALOG_HDISCIPLINEPUNISH
Class59=CBrowseDlg
Resource31=IDD_DIALOG_EDUCATIONDEGREE
Class60=CSearchDlg
Resource32=IDD_DIALOG_POSITIONINFORMATION
Class61=CStatisticsDlg
Resource33=IDD_DIALOG_NATIONINFORMATION
Class62=CNotesSet
Class63=CNotesDlg
Resource34=IDD_DIALOG_DEPARTMENTSECTION
Class64=CContactsSet
Class65=CContactsDlg
Resource35=IDD_DIALOG_HACADEMICEDUCATION
Class66=CNewCThinDlg
Resource36=IDD_DIALOG_HSTATISTICS
Class67=CMeetingRecordSet
Class68=CMeetingRecordDlg
Resource37=IDD_DIALOG_MEETINGRECORD

[CLS:CDatabaseApp]
Type=0
HeaderFile=Database.h
ImplementationFile=Database.cpp
Filter=N
LastObject=CDatabaseApp

[CLS:CDatabaseDoc]
Type=0
HeaderFile=DatabaseDoc.h
ImplementationFile=DatabaseDoc.cpp
Filter=N

[CLS:CDatabaseView]
Type=0
HeaderFile=DatabaseView.h
ImplementationFile=DatabaseView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDatabaseView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_HELP_DOCUMENT




[CLS:CAboutDlg]
Type=0
HeaderFile=Database.cpp
ImplementationFile=Database.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_SYS_USERSETTING
Command2=ID_SYS_RELOAD
Command3=ID_INF_EDUCATION
Command4=ID_INF_TECHNICAL
Command5=ID_ORG_DEPT
Command6=ID_ORG_SECTION
Command7=ID_HUMAN_BROWSE
Command8=ID_HUMAN_QUERY
Command9=ID_HUMAN_STATISTICS
Command10=ID_TOOL_NOTES
Command11=ID_TOOL_CONTACTS
Command12=ID_TOOL_MEETING
CommandCount=12

[MNU:IDR_MENU1]
Type=1
Class=CDatabaseView
Command1=ID_SYS_USERSETTING
Command2=ID_SYS_DBBACKUP
Command3=ID_SYS_DBRECOVER
Command4=ID_SYS_RELOAD
Command5=ID_SYS_EXIT
Command6=ID_INF_NATION
Command7=ID_INF_POSITION
Command8=ID_INF_EDUCATION
Command9=ID_INF_POLITICAL
Command10=ID_INF_DEPT
Command11=ID_INF_WAGE
Command12=ID_INF_TECHNICAL
Command13=ID_INF_ADMIN
Command14=ID_ORG_DEPT
Command15=ID_ORG_SECTION
Command16=ID_ORG_AUXILIARY
Command17=ID_ORG_APPENDANT
Command18=ID_ORG_FULLTIME
Command19=ID_HUMAN_BROWSE
Command20=ID_HUMAN_QUERY
Command21=ID_HUMAN_STATISTICS
Command22=ID_TOOL_NOTES
Command23=ID_TOOL_CONTACTS
Command24=ID_TOOL_MEETING
Command25=ID_HELP_ABOUT
Command26=ID_HELP_DOCUMENT
CommandCount=26

[CLS:CUser]
Type=0
HeaderFile=User.h
ImplementationFile=User.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CUser

[DB:CUser]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[customer], 12, 510
Column2=[password], 12, 510
Column3=[privilege], -7, 1

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1350565902
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO_USER,combobox,1344340226
Control7=IDC_EDIT_PASSWORD,edit,1350631584
Control8=IDC_STATIC,static,1342308352

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDCANCEL

[DLG:IDD_DIALOG_USERSETTING]
Type=1
Class=CUserSettingDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTTON_ADD,button,1342242816
Control6=IDC_BUTTON_DELETE,button,1342242816
Control7=IDC_BUTTON_CANCEL,button,1342242816
Control8=IDC_LIST_USERLIST,SysListView32,1350631429
Control9=IDC_EDIT_USERNAME,edit,1484849280
Control10=IDC_EDIT_PASSWORD,edit,1350631584
Control11=IDC_EDIT_CONFIRM,edit,1350631584
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_CHECK_AUTHORITY,button,1342242819

[CLS:CUserSettingDlg]
Type=0
HeaderFile=UserSettingDlg.h
ImplementationFile=UserSettingDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_SYS_USERSETTING

[DLG:IDD_DIALOG_COMMON]
Type=1
Class=CAddBaseInfoDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_ADD,button,1342177287
Control4=IDC_STATIC_INFORMATION,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_DATA,edit,1350631552
Control7=IDC_EDIT_DESCRIPTION,edit,1350631556

[CLS:CAddBaseInfoDlg]
Type=0
HeaderFile=AddBaseInfoDlg.h
ImplementationFile=AddBaseInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[CLS:CNationInformationSet]
Type=0
HeaderFile=NationInformationSet.h
ImplementationFile=NationInformationSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CNationInformationSet

[DB:CNationInformationSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[folk], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_NATIONINFORMATION]
Type=1
Class=CNationInformationDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_NATIONINFORMATION,SysListView32,1350631425

[CLS:CNationInformationDlg]
Type=0
HeaderFile=NationInformationDlg.h
ImplementationFile=NationInformationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNationInformationDlg

[CLS:CPositionInformationSet]
Type=0
HeaderFile=PositionInformationSet.h
ImplementationFile=PositionInformationSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPositionInformationSet

[DB:CPositionInformationSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[post], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_POSITIONINFORMATION]
Type=1
Class=CPositionInformationDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_POSITIONINFORMATON,SysListView32,1350631425

[CLS:CPositionInformationDlg]
Type=0
HeaderFile=PositionInformationDlg.h
ImplementationFile=PositionInformationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPositionInformationDlg

[CLS:CEducationDegreeSet]
Type=0
HeaderFile=EducationDegreeSet.h
ImplementationFile=EducationDegreeSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CEducationDegreeSet

[DB:CEducationDegreeSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[degree], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_EDUCATIONDEGREE]
Type=1
Class=CEducationDegreeDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_EDUCATIONDEGREE,SysListView32,1350631425

[CLS:CEducationDegreeDlg]
Type=0
HeaderFile=EducationDegreeDlg.h
ImplementationFile=EducationDegreeDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEducationDegreeDlg

[CLS:CPoliticalStatusSet]
Type=0
HeaderFile=PoliticalStatusSet.h
ImplementationFile=PoliticalStatusSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPoliticalStatusSet

[DB:CPoliticalStatusSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[party], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_POLITICALSTATUS]
Type=1
Class=CPoliticalStatusDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_POLITICALSTATUS,SysListView32,1350631425

[CLS:CPoliticalStatusDlg]
Type=0
HeaderFile=PoliticalStatusDlg.h
ImplementationFile=PoliticalStatusDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPoliticalStatusDlg

[CLS:CDepartmentSectionSet]
Type=0
HeaderFile=DepartmentSectionSet.h
ImplementationFile=DepartmentSectionSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CDepartmentSectionSet

[DB:CDepartmentSectionSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[division], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_DEPARTMENTSECTION]
Type=1
Class=CDepartmentSectionDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_DEPARTMENTSECTION,SysListView32,1350631425

[CLS:CDepartmentSectionDlg]
Type=0
HeaderFile=DepartmentSectionDlg.h
ImplementationFile=DepartmentSectionDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDepartmentSectionDlg

[CLS:CWageLevelSet]
Type=0
HeaderFile=WageLevelSet.h
ImplementationFile=WageLevelSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CWageLevelSet

[DB:CWageLevelSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[salary], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_WAGELEVEL]
Type=1
Class=CWageLevelDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_WAGELEVEL,SysListView32,1350631425

[CLS:CWageLevelDlg]
Type=0
HeaderFile=WageLevelDlg.h
ImplementationFile=WageLevelDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_INF_WAGE

[CLS:CTechnicalPostSet]
Type=0
HeaderFile=TechnicalPostSet.h
ImplementationFile=TechnicalPostSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTechnicalPostSet

[DB:CTechnicalPostSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[title], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_TECHNICALPOST]
Type=1
Class=CTechnicalPostDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_TECHNICALPOST,SysListView32,1350631425

[CLS:CTechnicalPostDlg]
Type=0
HeaderFile=TechnicalPostDlg.h
ImplementationFile=TechnicalPostDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTechnicalPostDlg

[CLS:CAdministrativePostSet]
Type=0
HeaderFile=AdministrativePostSet.h
ImplementationFile=AdministrativePostSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAdministrativePostSet

[DB:CAdministrativePostSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[rank], 12, 510
Column3=[description], 12, 510

[DLG:IDD_DIALOG_ADMINISTRATIVEPOST]
Type=1
Class=CAdministrativePostDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST_ADMINISTRATIVEPOST,SysListView32,1350631425

[CLS:CAdministrativePostDlg]
Type=0
HeaderFile=AdministrativePostDlg.h
ImplementationFile=AdministrativePostDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAdministrativePostDlg

[CLS:CDepartmentSet]
Type=0
HeaderFile=DepartmentSet.h
ImplementationFile=DepartmentSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CDepartmentSet

[DB:CDepartmentSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[leader], 12, 510
Column4=[location], 12, 510
Column5=[organization], 12, 510
Column6=[teach], 12, 510
Column7=[research], 12, 510
Column8=[student], 12, 510

[DLG:IDD_DIALOG_DEPARTMENT]
Type=1
Class=CDepartmentDlg
ControlCount=30
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_CODE,edit,1350631552
Control13=IDC_EDIT_LOCATION,edit,1350631552
Control14=IDC_EDIT_SETTING,edit,1350631552
Control15=IDC_EDIT_TEACHING,edit,1350631552
Control16=IDC_EDIT_RESEARCHING,edit,1350631552
Control17=IDC_EDIT_STUDENT,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO_LEADER,combobox,1344340226
Control20=IDC_COMBO_NAME,combobox,1344340226
Control21=IDC_BUTTON_ADD,button,1342242816
Control22=IDC_BUTTON_SAVE,button,1476460544
Control23=IDC_BUTTON_UPDATE,button,1342242816
Control24=IDC_BUTTON_DELETE,button,1342242816
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_COMBO_CONDITION,combobox,1344340226
Control28=IDC_EDIT_CONTENT,edit,1350631552
Control29=IDC_BUTTON_SEARCH,button,1342242816
Control30=IDC_LIST_DEPARTMENT,SysListView32,1350631425

[CLS:CDepartmentDlg]
Type=0
HeaderFile=DepartmentDlg.h
ImplementationFile=DepartmentDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDepartmentDlg

[CLS:CSectionSet]
Type=0
HeaderFile=SectionSet.h
ImplementationFile=SectionSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CSectionSet

[DB:CSectionSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[leader], 12, 510
Column4=[location], 12, 510
Column5=[organization], 12, 510
Column6=[rule], 12, 510

[DLG:IDD_DIALOG_SECTION]
Type=1
Class=CSectionDlg
ControlCount=25
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_CODE,edit,1350631552
Control11=IDC_EDIT_LOCATION,edit,1350631552
Control12=IDC_EDIT_SETTING,edit,1350631552
Control13=IDC_EDIT_RULE,edit,1350631556
Control14=IDC_COMBO_NAME,combobox,1344340226
Control15=IDC_COMBO_LEADER,combobox,1344340226
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1476460544
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_DELETE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_COMBO_CONDITION,combobox,1344340226
Control23=IDC_EDIT_CONTENT,edit,1350631552
Control24=IDC_BUTTON_SEARCH,button,1342242816
Control25=IDC_LIST_SECTION,SysListView32,1350631425

[CLS:CSectionDlg]
Type=0
HeaderFile=SectionDlg.h
ImplementationFile=SectionDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSectionDlg

[CLS:CAuxiliarySet]
Type=0
HeaderFile=AuxiliarySet.h
ImplementationFile=AuxiliarySet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAuxiliarySet

[DB:CAuxiliarySet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[leader], 12, 510
Column4=[location], 12, 510
Column5=[organization], 12, 510
Column6=[duty], 12, 510

[DLG:IDD_DIALOG_AUXILIARY]
Type=1
Class=CAuxiliaryDlg
ControlCount=25
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_CODE,edit,1350631552
Control11=IDC_EDIT_LOCATION,edit,1350631552
Control12=IDC_COMBO_LEADER,combobox,1344340226
Control13=IDC_COMBO_NAME,combobox,1344340226
Control14=IDC_EDIT_SETTING,edit,1350631552
Control15=IDC_EDIT_DUTY,edit,1350631556
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1476460544
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_DELETE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_COMBO_CONDITION,combobox,1344340226
Control23=IDC_EDIT_CONTENT,edit,1350631552
Control24=IDC_BUTTON_SEARCH,button,1342242816
Control25=IDC_LIST_AUXILIARY,SysListView32,1350631425

[CLS:CAuxiliaryDlg]
Type=0
HeaderFile=AuxiliaryDlg.h
ImplementationFile=AuxiliaryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAuxiliaryDlg

[CLS:CAppendantSet]
Type=0
HeaderFile=AppendantSet.h
ImplementationFile=AppendantSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAppendantSet

[DB:CAppendantSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[leader], 12, 510
Column4=[location], 12, 510
Column5=[organization], 12, 510
Column6=[regulation], 12, 510

[DLG:IDD_DIALOG_APPENDANT]
Type=1
Class=CAppendantDlg
ControlCount=25
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_CODE,edit,1350631552
Control11=IDC_EDIT_LOCATION,edit,1350631552
Control12=IDC_EDIT_SETTING,edit,1350631552
Control13=IDC_EDIT_REGULATION,edit,1350631556
Control14=IDC_COMBO_LEADER,combobox,1344340226
Control15=IDC_COMBO_NAME,combobox,1344340226
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1476460544
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_DELETE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_COMBO_CONDITION,combobox,1344340226
Control23=IDC_EDIT_CONTENT,edit,1350631552
Control24=IDC_BUTTON_SEARCH,button,1342242816
Control25=IDC_LIST_APPENDANT,SysListView32,1350631425

[CLS:CAppendantDlg]
Type=0
HeaderFile=AppendantDlg.h
ImplementationFile=AppendantDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAppendantDlg

[CLS:CFulltimeSet]
Type=0
HeaderFile=FulltimeSet.h
ImplementationFile=FulltimeSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFulltimeSet

[DB:CFulltimeSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[leader], 12, 510
Column4=[location], 12, 510
Column5=[organization], 12, 510
Column6=[fruit], 12, 510

[DLG:IDD_DIALOG_FULLTIME]
Type=1
Class=CFulltimeDlg
ControlCount=25
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_CODE,edit,1350631552
Control11=IDC_EDIT_LOCATION,edit,1350631552
Control12=IDC_EDIT_SETTING,edit,1350631552
Control13=IDC_EDIT_FRUIT,edit,1350631556
Control14=IDC_COMBO_LEADER,combobox,1344340226
Control15=IDC_COMBO_NAME,combobox,1344340226
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1476460544
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_DELETE,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_COMBO_CONDITION,combobox,1344340226
Control23=IDC_EDIT_CONTENT,edit,1350631552
Control24=IDC_BUTTON_SEARCH,button,1342242816
Control25=IDC_LIST_FULLTIME,SysListView32,1350631425

[CLS:CFulltimeDlg]
Type=0
HeaderFile=FulltimeDlg.h
ImplementationFile=FulltimeDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFulltimeDlg

[CLS:CBaseArchiveDlg]
Type=0
HeaderFile=BaseArchiveDlg.h
ImplementationFile=BaseArchiveDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_CODE

[CLS:CStaffSet]
Type=0
HeaderFile=StaffSet.h
ImplementationFile=StaffSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CStaffSet]
DB=1
DBType=ODBC
ColumnCount=25
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[sex], 12, 510
Column4=[birth], 11, 16
Column5=[marriage], 12, 510
Column6=[age], 5, 2
Column7=[party], 12, 510
Column8=[race], 12, 510
Column9=[identity Card], 12, 510
Column10=[word Date], 11, 16
Column11=[post], 12, 510
Column12=[native], 12, 510
Column13=[enty Date], 11, 16
Column14=[salary], 12, 510
Column15=[degree], 12, 510
Column16=[department], 12, 510
Column17=[technical], 12, 510
Column18=[job], 12, 510
Column19=[office Phone], 12, 510
Column20=[mobile Phone], 12, 510
Column21=[email], 12, 510
Column22=[university], 12, 510
Column23=[subject], 12, 510
Column24=[graduate Date], 11, 16
Column25=[address], 12, 510

[CLS:CFamilyMemberSet]
Type=0
HeaderFile=FamilyMemberSet.h
ImplementationFile=FamilyMemberSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFamilyMemberSet

[DB:CFamilyMemberSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[name], 12, 510
Column4=[identity Card], 12, 510
Column5=[relation], 12, 510
Column6=[birth], 11, 16
Column7=[company], 12, 510
Column8=[phone], 12, 510
Column9=[duty], 12, 510
Column10=[political], 12, 510
Column11=[education], 12, 510

[DLG:IDD_DIALOG_HFAMILYMEMBER]
Type=1
Class=CFamilyMemberDlg
ControlCount=23
Control1=IDC_LIST_FAMILY,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_DATETIMEPICKER_BIRTH,SysDateTimePick32,1342242865
Control12=IDC_EDIT_NAME,edit,1350631552
Control13=IDC_EDIT_CID,edit,1350631552
Control14=IDC_EDIT_RELATION,edit,1350631552
Control15=IDC_EDIT_COMPANY,edit,1350631552
Control16=IDC_EDIT_PHONE,edit,1350631552
Control17=IDC_EDIT_DUTY,edit,1350631552
Control18=IDC_COMBO_POLITICAL,combobox,1344340226
Control19=IDC_EDIT_EDUCATION,edit,1350631552
Control20=IDC_BUTTON_ADD,button,1342242816
Control21=IDC_BUTTON_DELETE,button,1342242816
Control22=IDC_BUTTON_UPDATE,button,1342242816
Control23=IDC_BUTTON_SAVE,button,1342242816

[CLS:CFamilyMemberDlg]
Type=0
HeaderFile=FamilyMemberDlg.h
ImplementationFile=FamilyMemberDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFamilyMemberDlg

[CLS:CWorkExperienceSet]
Type=0
HeaderFile=WorkExperienceSet.h
ImplementationFile=WorkExperienceSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CWorkExperienceSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[begin Date], 11, 16
Column4=[end Date], 11, 16
Column5=[company], 12, 510
Column6=[department], 12, 510
Column7=[duty], 12, 510
Column8=[technical], 12, 510
Column9=[education], 12, 510
Column10=[location], 12, 510
Column11=[proof], 12, 510

[DLG:IDD_DIALOG_HWORKEXPERIENCE]
Type=1
Class=CWorkExperienceDlg
ControlCount=23
Control1=IDC_LIST_WORKEXPERIENCE,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_DATETIMEPICKER_BEGIN,SysDateTimePick32,1342242865
Control12=IDC_DATETIMEPICKER_END,SysDateTimePick32,1342242865
Control13=IDC_EDIT_COMPANY,edit,1350631552
Control14=IDC_EDIT_DEPARTMENT,edit,1350631552
Control15=IDC_EDIT_DUTY,edit,1350631552
Control16=IDC_EDIT_TECHNICAL,edit,1350631552
Control17=IDC_COMBO_EDUCATION,combobox,1344340226
Control18=IDC_EDIT_LOCATION,edit,1350631552
Control19=IDC_EDIT_PROVER,edit,1350631552
Control20=IDC_BUTTON_ADD,button,1342242816
Control21=IDC_BUTTON_DELETE,button,1342242816
Control22=IDC_BUTTON_UPDATE,button,1342242816
Control23=IDC_BUTTON_SAVE,button,1342242816

[CLS:CWorkExperienceDlg]
Type=0
HeaderFile=WorkExperienceDlg.h
ImplementationFile=WorkExperienceDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CWorkExperienceDlg

[CLS:CRewardRecordSet]
Type=0
HeaderFile=RewardRecordSet.h
ImplementationFile=RewardRecordSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CRewardRecordSet

[DB:CRewardRecordSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[title], 12, 510
Column4=[sort], 12, 510
Column5=[level], 12, 510
Column6=[unit], 12, 510
Column7=[category], 12, 510
Column8=[date], 11, 16

[DLG:IDD_DIALOG_HREWARDRECORD]
Type=1
Class=CRewardRecordDlg
ControlCount=17
Control1=IDC_LIST_REWARDRECORD,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_TITLE,edit,1350631552
Control9=IDC_COMBO_SORT,combobox,1344340226
Control10=IDC_COMBO_LEVEL,combobox,1344340226
Control11=IDC_EDIT_UNIT,edit,1350631552
Control12=IDC_COMBO_CATEGORY,combobox,1344340226
Control13=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242865
Control14=IDC_BUTTON_ADD,button,1342242816
Control15=IDC_BUTTON_DELETE,button,1342242816
Control16=IDC_BUTTON_UPDATE,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1342242816

[CLS:CRewardRecordDlg]
Type=0
HeaderFile=RewardRecordDlg.h
ImplementationFile=RewardRecordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRewardRecordDlg

[CLS:CDisciplinePunishSet]
Type=0
HeaderFile=DisciplinePunishSet.h
ImplementationFile=DisciplinePunishSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CDisciplinePunishSet

[DB:CDisciplinePunishSet]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[sort], 12, 510
Column4=[period], 12, 510
Column5=[preason], 12, 510
Column6=[pdate], 11, 16
Column7=[ddate], 11, 16
Column8=[dreason], 12, 510
Column9=[unit], 12, 510

[DLG:IDD_DIALOG_HDISCIPLINEPUNISH]
Type=1
Class=CDisciplinePunishDlg
ControlCount=19
Control1=IDC_LIST_DISCIPLINEPUNISH,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBO_SORT,combobox,1344340226
Control10=IDC_COMBO_PERIOD,combobox,1344340226
Control11=IDC_EDIT_PREASON,edit,1350631552
Control12=IDC_DATETIMEPICKER_PDATE,SysDateTimePick32,1342242865
Control13=IDC_DATETIMEPICKER_DDATE,SysDateTimePick32,1342242865
Control14=IDC_EDIT_DREASON,edit,1350631552
Control15=IDC_EDIT_UNIT1,edit,1350631552
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_DELETE,button,1342242816
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_SAVE,button,1342242816

[CLS:CDisciplinePunishDlg]
Type=0
HeaderFile=DisciplinePunishDlg.h
ImplementationFile=DisciplinePunishDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDisciplinePunishDlg

[CLS:CPaperSet1]
Type=0
HeaderFile=PaperSet1.h
ImplementationFile=PaperSet1.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPaperSet1

[DB:CPaperSet1]
DB=1
DBType=ODBC
ColumnCount=13
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[title], 12, 510
Column4=[rank], 12, 510
Column5=[publication], 12, 510
Column6=[pub time], 11, 16
Column7=[pub year], 12, 510
Column8=[volume], 12, 510
Column9=[issue], 12, 510
Column10=[page], 12, 510
Column11=[level], 12, 510
Column12=[type], 12, 510
Column13=[index], 12, 510

[DLG:IDD_DIALOG_HPAPER]
Type=1
Class=CPaperDlg
ControlCount=27
Control1=IDC_LIST_PAPER,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_TITLE,edit,1350631552
Control14=IDC_COMBO_RANK,combobox,1344340226
Control15=IDC_EDIT_PUBLICATION,edit,1350631552
Control16=IDC_DATETIMEPICKER_PUBTIME,SysDateTimePick32,1342242865
Control17=IDC_EDIT_PUBTIME,edit,1350631552
Control18=IDC_EDIT_VOLUME,edit,1350631552
Control19=IDC_EDIT_ISSUE,edit,1350631552
Control20=IDC_EDIT_PAGE,edit,1350631552
Control21=IDC_COMBO_LEVEL,combobox,1344340226
Control22=IDC_COMBO_TYPE,combobox,1344340226
Control23=IDC_COMBO_INDEX,combobox,1344340226
Control24=IDC_BUTTON_ADD,button,1342242816
Control25=IDC_BUTTON_DELETE,button,1342242816
Control26=IDC_BUTTON_UPDATE,button,1342242816
Control27=IDC_BUTTON_SAVE,button,1342242816

[CLS:CPaperDlg]
Type=0
HeaderFile=PaperDlg.h
ImplementationFile=PaperDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_ADD

[CLS:CProjectSet]
Type=0
HeaderFile=ProjectSet.h
ImplementationFile=ProjectSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CProjectSet

[DB:CProjectSet]
DB=1
DBType=ODBC
ColumnCount=17
Column1=[numder], 4, 4
Column2=[code], 12, 510
Column3=[title], 12, 510
Column4=[type], 12, 510
Column5=[sort], 12, 510
Column6=[level], 12, 510
Column7=[rate], 12, 510
Column8=[state], 12, 510
Column9=[host], 12, 510
Column10=[rank], 12, 510
Column11=[first], 12, 510
Column12=[release], 11, 16
Column13=[unit], 12, 510
Column14=[cost], 12, 510
Column15=[limit], 12, 510
Column16=[begin], 11, 16
Column17=[end], 11, 16

[DLG:IDD_DIALOG_HPROJECT]
Type=1
Class=CProjectDlg
ControlCount=35
Control1=IDC_LIST_PROJECT,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_TITLE,edit,1350631552
Control18=IDC_COMBO_TYPE,combobox,1344340226
Control19=IDC_COMBO_SORT,combobox,1344340226
Control20=IDC_COMBO_LEVEL,combobox,1344340226
Control21=IDC_COMBO_RATE,combobox,1344340226
Control22=IDC_COMBO_STATE,combobox,1344340226
Control23=IDC_EDIT_HOST,edit,1350631552
Control24=IDC_EDIT_FIRST,edit,1350631552
Control25=IDC_EDIT_RANK,edit,1350631552
Control26=IDC_DATETIMEPICKER_RELEASE,SysDateTimePick32,1342242865
Control27=IDC_EDIT_UNIT2,edit,1350631552
Control28=IDC_EDIT_COST,edit,1350631552
Control29=IDC_COMBO_LIMIT,combobox,1344340226
Control30=IDC_DATETIMEPICKER_BEGIN,SysDateTimePick32,1342242865
Control31=IDC_DATETIMEPICKER_END,SysDateTimePick32,1342242865
Control32=IDC_BUTTON_ADD,button,1342242816
Control33=IDC_BUTTON_DELETE,button,1342242816
Control34=IDC_BUTTON_UPDATE,button,1342242816
Control35=IDC_BUTTON_SAVE,button,1342242816

[CLS:CProjectDlg]
Type=0
HeaderFile=ProjectDlg.h
ImplementationFile=ProjectDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProjectDlg

[CLS:CTechnicalAccessSet]
Type=0
HeaderFile=TechnicalAccessSet.h
ImplementationFile=TechnicalAccessSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTechnicalAccessSet

[DB:CTechnicalAccessSet]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[numder], 4, 4
Column2=[code], 12, 510
Column3=[title], 12, 510
Column4=[mode], 12, 510
Column5=[unit], 12, 510
Column6=[assess Date], 11, 16
Column7=[hire], 12, 510
Column8=[begin], 11, 16
Column9=[end], 11, 16
Column10=[employ], 12, 510

[DLG:IDD_DIALOG_HTECHNICALACCESS]
Type=1
Class=CTechnicalAccessDlg
ControlCount=21
Control1=IDC_LIST_TECHNICALACCESS,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_TITLE,edit,1350631552
Control11=IDC_COMBO_MODE,combobox,1344340226
Control12=IDC_EDIT_UNIT,edit,1350631552
Control13=IDC_DATETIMEPICKER_GDATE,SysDateTimePick32,1342242865
Control14=IDC_EDIT_HIRE,edit,1350631552
Control15=IDC_EDIT_EMPLOY,edit,1350631552
Control16=IDC_DATETIMEPICKER_BDATE,SysDateTimePick32,1342242865
Control17=IDC_DATETIMEPICKER_EDATE,SysDateTimePick32,1342242865
Control18=IDC_BUTTON_ADD,button,1342242816
Control19=IDC_BUTTON_DELETE,button,1342242816
Control20=IDC_BUTTON_UPDATE,button,1342242816
Control21=IDC_BUTTON_SAVE,button,1342242816

[CLS:CTechnicalAccessDlg]
Type=0
HeaderFile=TechnicalAccessDlg.h
ImplementationFile=TechnicalAccessDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTechnicalAccessDlg

[CLS:CAcademicEducationSet]
Type=0
HeaderFile=AcademicEducationSet.h
ImplementationFile=AcademicEducationSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAcademicEducationSet

[DB:CAcademicEducationSet]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[begin], 11, 16
Column4=[end], 11, 16
Column5=[university], 12, 510
Column6=[department], 12, 510
Column7=[major], 12, 510
Column8=[diploma], 12, 510
Column9=[degree], 12, 510

[DLG:IDD_DIALOG_HACADEMICEDUCATION]
Type=1
Class=CAcademicEducationDlg
ControlCount=19
Control1=IDC_LIST_ACADEMICEDUCATION,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DATETIMEPICKER_BDATE,SysDateTimePick32,1342242865
Control10=IDC_DATETIMEPICKER_EDATE,SysDateTimePick32,1342242865
Control11=IDC_EDIT_UNIVERSITY,edit,1350631552
Control12=IDC_EDIT_DEPARTMENT,edit,1350631552
Control13=IDC_EDIT_MAJOR,edit,1350631552
Control14=IDC_COMBO_DIPLOMA,combobox,1344340226
Control15=IDC_COMBO_DEGREE,combobox,1344340226
Control16=IDC_BUTTON_ADD,button,1342242816
Control17=IDC_BUTTON_DELETE,button,1342242816
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_SAVE,button,1342242816

[CLS:CAcademicEducationDlg]
Type=0
HeaderFile=AcademicEducationDlg.h
ImplementationFile=AcademicEducationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAcademicEducationDlg

[CLS:CContinueEducationSet]
Type=0
HeaderFile=ContinueEducationSet.h
ImplementationFile=ContinueEducationSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CContinueEducationSet

[DB:CContinueEducationSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[begin], 11, 16
Column4=[end], 11, 16
Column5=[mode], 12, 510
Column6=[effect], 12, 510
Column7=[content], 12, 510
Column8=[unit], 12, 510
Column9=[location], 12, 510
Column10=[cost], 12, 510
Column11=[hour], 12, 510

[DLG:IDD_DIALOG_HCONTINUEEDUCATION]
Type=1
Class=CContinueEducationDlg
ControlCount=23
Control1=IDC_LIST_CONTINUEEDUCATION,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO_MODE,combobox,1344340226
Control12=IDC_DATETIMEPICKER_BDATE,SysDateTimePick32,1342242865
Control13=IDC_DATETIMEPICKER_EDATE,SysDateTimePick32,1342242865
Control14=IDC_COMBO_EFFECT,combobox,1344340226
Control15=IDC_EDIT_CONTENT,edit,1350631552
Control16=IDC_EDIT_UNIT,edit,1350631552
Control17=IDC_EDIT_LOCATION,edit,1350631552
Control18=IDC_EDIT_COST,edit,1350631552
Control19=IDC_EDIT_HOUR,edit,1350631552
Control20=IDC_BUTTON_ADD,button,1342242816
Control21=IDC_BUTTON_DELETE,button,1342242816
Control22=IDC_BUTTON_UPDATE,button,1342242816
Control23=IDC_BUTTON_SAVE,button,1342242816

[CLS:CContinueEducationDlg]
Type=0
HeaderFile=ContinueEducationDlg.h
ImplementationFile=ContinueEducationDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CContinueEducationDlg

[CLS:CClassTeachingSet]
Type=0
HeaderFile=ClassTeachingSet.h
ImplementationFile=ClassTeachingSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CClassTeachingSet

[DB:CClassTeachingSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[number], 4, 4
Column2=[code], 12, 510
Column3=[annual], 12, 510
Column4=[semester], 12, 510
Column5=[course], 12, 510
Column6=[sort], 12, 510
Column7=[level], 12, 510
Column8=[class], 12, 510
Column9=[object], 12, 510
Column10=[location], 12, 510
Column11=[hour], 12, 510

[DLG:IDD_DIALOG_HCLASSTEACHING]
Type=1
Class=CClassTeachingDlg
ControlCount=23
Control1=IDC_LIST_CLASSTEACHING,SysListView32,1350631429
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_ANNUAL,edit,1350631552
Control12=IDC_COMBO_SEMESTER,combobox,1344340226
Control13=IDC_EDIT_COURSE,edit,1350631552
Control14=IDC_COMBO_SORT,combobox,1344340226
Control15=IDC_COMBO_LEVEL,combobox,1344340226
Control16=IDC_EDIT_CLASS,edit,1350631552
Control17=IDC_COMBO_OBJECT,combobox,1344340226
Control18=IDC_EDIT_HOUR,edit,1350631552
Control19=IDC_EDIT_LOCATION,edit,1350631552
Control20=IDC_BUTTON_ADD,button,1342242816
Control21=IDC_BUTTON_DELETE,button,1342242816
Control22=IDC_BUTTON_UPDATE,button,1342242816
Control23=IDC_BUTTON_SAVE,button,1342242816

[CLS:CClassTeachingDlg]
Type=0
HeaderFile=ClassTeachingDlg.h
ImplementationFile=ClassTeachingDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CClassTeachingDlg

[CLS:CContainer]
Type=0
HeaderFile=Container.h
ImplementationFile=Container.cpp
BaseClass=CTabCtrl
Filter=W
VirtualFilter=UWC
LastObject=CContainer

[DLG:IDD_DIALOG_BROWSE]
Type=1
Class=CBrowseDlg
ControlCount=19
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO_CONDITION,combobox,1344340035
Control7=IDC_COMBO_CONTENT,combobox,1344340034
Control8=IDC_BUTTON_SEARCH,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_NAME,edit,1350633600
Control12=IDC_EDIT_CODE,edit,1350633600
Control13=IDC_LIST_BROWSE,SysListView32,1350631429
Control14=IDC_TAB_BROWSE,SysTabControl32,1342177280
Control15=IDC_BUTTON_ADD,button,1342242816
Control16=IDC_BUTTON_DELETE,button,1342242816
Control17=IDC_BUTTON_SAVE,button,1342242816
Control18=IDC_BUTTON_UPDATE,button,1342242816
Control19=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CBrowseDlg]
Type=0
HeaderFile=BrowseDlg.h
ImplementationFile=BrowseDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBrowseDlg

[DLG:IDD_HUMAN_HBASEARCHIVE]
Type=1
Class=CBaseArchiveDlg
ControlCount=50
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_EDIT_CODE,edit,1484849280
Control27=IDC_EDIT_NAME,edit,1350631552
Control28=IDC_COMBO_SEX,combobox,1344339970
Control29=IDC_DATETIMEPICKER_BIRTH,SysDateTimePick32,1342242865
Control30=IDC_COMBO_MARRYIAGE,combobox,1344340226
Control31=IDC_EDIT_AGE,edit,1350631552
Control32=IDC_COMBO_PARTY,combobox,1344340226
Control33=IDC_COMBO_RACE,combobox,1344339970
Control34=IDC_EDIT_CID,edit,1350631552
Control35=IDC_DATETIMEPICKER_WORK,SysDateTimePick32,1342242865
Control36=IDC_COMBO_POST,combobox,1344340226
Control37=IDC_EDIT_NATIVE,edit,1350631552
Control38=IDC_DATETIMEPICKER_ENTRY,SysDateTimePick32,1342242865
Control39=IDC_COMBO_SALARY,combobox,1344340226
Control40=IDC_COMBO_DEGREE,combobox,1344340226
Control41=IDC_COMBO_DEPTMENT,combobox,1344340226
Control42=IDC_COMBO_TECHNICAL,combobox,1344340226
Control43=IDC_COMBO_JOB,combobox,1344340226
Control44=IDC_EDIT_OPHONE,edit,1350631552
Control45=IDC_EDIT_MPHONE,edit,1350631552
Control46=IDC_EDIT_EMAIL,edit,1350631552
Control47=IDC_EDIT_UNIVERSITY,edit,1350631552
Control48=IDC_EDIT_SUBJECT,edit,1350631552
Control49=IDC_DATETIMEPICKER_GRADUAGE,SysDateTimePick32,1342242865
Control50=IDC_EDIT_ADDRESS,edit,1350631552

[DLG:IDD_DIALOG_HSEARCH]
Type=1
Class=CSearchDlg
ControlCount=29
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_NAME,edit,1350631552
Control15=IDC_COMBO_SEX,combobox,1344339970
Control16=IDC_EDIT_AGE,edit,1350631552
Control17=IDC_COMBO_NATION,combobox,1344339970
Control18=IDC_EDIT_NATIVE,edit,1350631552
Control19=IDC_COMBO_MARRIAGE,combobox,1344339970
Control20=IDC_COMBO_TECHNICAL,combobox,1344339970
Control21=IDC_COMBO_POST,combobox,1344339970
Control22=IDC_COMBO_EDUCATION,combobox,1344339970
Control23=IDC_COMBO_POLITICAL,combobox,1344339970
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_UNIT,combobox,1344340226
Control27=IDC_COMBO_POSITION,combobox,1344340226
Control28=IDC_LIST_SEARCH,SysListView32,1350631949
Control29=IDC_BUTTON_SEARCH,button,1342242816

[CLS:CSearchDlg]
Type=0
HeaderFile=SearchDlg.h
ImplementationFile=SearchDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSearchDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_HSTATISTICS]
Type=1
Class=CStatisticsDlg
ControlCount=2
Control1=IDC_SELECTION,SysListView32,1350639629
Control2=IDC_RESULT,SysListView32,1350631425

[CLS:CStatisticsDlg]
Type=0
HeaderFile=StatisticsDlg.h
ImplementationFile=StatisticsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CStatisticsDlg

[CLS:CNotesSet]
Type=0
HeaderFile=NotesSet.h
ImplementationFile=NotesSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CNotesSet

[DB:CNotesSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[number], 4, 4
Column2=[rDate], 11, 16
Column3=[writer], 12, 510
Column4=[wUnit], 12, 510
Column5=[type], 12, 510
Column6=[title], 12, 510
Column7=[content], 12, 510

[DLG:IDD_DIALOG_NOTES]
Type=1
Class=CNotesDlg
ControlCount=26
Control1=IDOK,button,1476460545
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_ADD,button,1342242816
Control4=IDC_BUTTON_DELETE,button,1342242816
Control5=IDC_BUTTON_UPDATE,button,1342242816
Control6=IDC_BUTTON_CANCEL,button,1476460544
Control7=IDC_BUTTON_SEARCH,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_CONDITION,combobox,1344339971
Control14=IDC_EDIT_CONTENT,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT_WRITER,edit,1350631552
Control21=IDC_EDIT_UNIT1,edit,1350631552
Control22=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242865
Control23=IDC_COMBO_TYPE,combobox,1344340226
Control24=IDC_EDIT_TITLE,edit,1350631552
Control25=IDC_EDIT_CONTEXT,edit,1350631556
Control26=IDC_LIST_NOTES,SysListView32,1350631425

[CLS:CNotesDlg]
Type=0
HeaderFile=NotesDlg.h
ImplementationFile=NotesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_ADD

[CLS:CContactsSet]
Type=0
HeaderFile=ContactsSet.h
ImplementationFile=ContactsSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CContactsSet

[DB:CContactsSet]
DB=1
DBType=ODBC
ColumnCount=12
Column1=[number], 4, 4
Column2=[name], 12, 510
Column3=[sex], 12, 510
Column4=[fPhone], 12, 510
Column5=[oPhone], 12, 510
Column6=[mPhone], 12, 510
Column7=[short], 12, 510
Column8=[QQ], 12, 510
Column9=[weChat], 12, 510
Column10=[email], 12, 510
Column11=[unit], 12, 510
Column12=[remark], 12, 510

[DLG:IDD_DIALOG_COMMUNICATIONTHIN]
Type=1
Class=CContactsDlg
ControlCount=12
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST_THIN,SysListView32,1350631425
Control3=IDC_BUTTON_VIEW,button,1342242816
Control4=IDC_BUTTON_ADD,button,1342242816
Control5=IDC_BUTTON_DELETE,button,1342242816
Control6=IDC_BUTTON_UPDATE,button,1342242816
Control7=IDC_BUTTON_SEARCH,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO_CONDITION,combobox,1344340227
Control12=IDC_EDIT_CONTENT,edit,1350631552

[CLS:CContactsDlg]
Type=0
HeaderFile=ContactsDlg.h
ImplementationFile=ContactsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CContactsDlg

[DLG:IDD_DIALOG_NEWCTHIN]
Type=1
Class=CNewCThinDlg
ControlCount=25
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_NAME,edit,1350631552
Control16=IDC_EDIT_FPHONE,edit,1350631552
Control17=IDC_COMBO_SEX,combobox,1344340226
Control18=IDC_EDIT_OPHONE,edit,1350631552
Control19=IDC_EDIT_MPHONE,edit,1350631552
Control20=IDC_EDIT_SHORT,edit,1350631552
Control21=IDC_EDIT_QQ,edit,1350631552
Control22=IDC_EDIT_WECHAT,edit,1350631552
Control23=IDC_EDIT_EMAIL,edit,1350631552
Control24=IDC_EDIT_UNIT1,edit,1350631552
Control25=IDC_EDIT_REMARK,edit,1350631556

[CLS:CNewCThinDlg]
Type=0
HeaderFile=NewCThinDlg.h
ImplementationFile=NewCThinDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[CLS:CMeetingRecordSet]
Type=0
HeaderFile=MeetingRecordSet.h
ImplementationFile=MeetingRecordSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CMeetingRecordSet

[DB:CMeetingRecordSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[number], 4, 4
Column2=[mDate], 11, 16
Column3=[location], 12, 510
Column4=[sort], 12, 510
Column5=[subject], 12, 510
Column6=[host Unit], 12, 510
Column7=[participate Unit], 12, 510
Column8=[host], 12, 510
Column9=[writer], 12, 510
Column10=[content], 12, 510
Column11=[remark], 12, 510

[DLG:IDD_DIALOG_MEETINGRECORD]
Type=1
Class=CMeetingRecordDlg
ControlCount=34
Control1=IDOK,button,1476460545
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_ADD,button,1342242816
Control4=IDC_BUTTON_DELETE,button,1342242816
Control5=IDC_BUTTON_UPDATE,button,1342242816
Control6=IDC_BUTTON_CANCEL,button,1476460544
Control7=IDC_BUTTON_SEARCH,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242865
Control21=IDC_EDIT_LOCATION,edit,1350631552
Control22=IDC_COMBO_SORT,combobox,1344340226
Control23=IDC_EDIT_SUBJECT,edit,1350631552
Control24=IDC_EDIT_HOSTUNIT,edit,1350631552
Control25=IDC_EDIT_PARTICIPATEUNIT,edit,1350631552
Control26=IDC_EDIT_HOST,edit,1350631552
Control27=IDC_EDIT_WRITER1,edit,1350631552
Control28=IDC_EDIT_CONTENT,edit,1350631556
Control29=IDC_EDIT_REMARK,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_CONDITION,combobox,1344340227
Control33=IDC_EDIT_DETAILS,edit,1350631552
Control34=IDC_LIST_MEETING,SysListView32,1350631425

[CLS:CMeetingRecordDlg]
Type=0
HeaderFile=MeetingRecordDlg.h
ImplementationFile=MeetingRecordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMeetingRecordDlg

