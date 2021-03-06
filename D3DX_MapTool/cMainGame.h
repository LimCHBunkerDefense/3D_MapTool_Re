#pragma once

class cCamera;
class cGrid;
class cHeightMap;
class cUITab;

class cUIScrollbar;
class cUITextView;
class cUIButton;
class cRadioButton;
class cUIInputField;

class cConstruct;
class cSkyBox;

class cMainGame
{
	D3DXVECTOR3					m_vStandardPos;
	D3DXVECTOR3					m_vDir;
	cCamera*					m_pCamera;
	cGrid*						m_pGrid;

	cHeightMap*					m_pMap;
	int							m_nSize;
	float						m_fCellSpace;
	float						m_fCamSpeed;

	bool						m_isUpdateMap;
	bool						m_isUpdateObj;
	LPD3DXSPRITE				m_pUISprite;
	cUITab*						m_pUITab_Menu;
	cUITab*						m_pUITab_Map;
	cUITab*						m_pUITab_Object;
	cUITab*						m_pUITab_Effect;

	vector<cUITab*>				m_vecUITab_Image;

	D3DXVECTOR3					m_vCursorPos;

	//>> Menu 탭 안 변수들
	cUIInputField*				m_pUIInputField_CellSpace;
	cUIInputField*				m_pUIInputField_CellNum;
	cUIInputField*				m_pUIInputField_FilePath;

	cUIButton*					m_pUIButton_create;
	cUIButton*					m_pUIButton_save;
	cUIButton*					m_pUIButton_load;
	//<<

	// >> Map 탭 안의 변수들
	cUIScrollbar*				m_pUIScroll_BrushSize_inside;
	cUIScrollbar*				m_pUIScroll_BrushDepth_inside;
	cUIScrollbar*				m_pUIScroll_BrushSize_Outside;
	cUIScrollbar*				m_pUIScroll_BrushSharpness;

	cRadioButton*				m_pRadioButton_Brush;
	cUIButton*					m_pUIButton_GetHeight;
	cUIInputField*				m_pUIInputField_SetHeight;
	cUIButton*					m_pUIButton_SetHeight;

	bool						m_getHeight;
	// << 

	// >> Object탭 안의 버튼과 텍스트 관련 변수
	cUIButton*              m_pUIButton_LLeft;
	cUIButton*              m_pUIButton_LRight;
	cUITextView*            m_pUIText_LID;

	cUIButton*              m_pUIButton_MLeft;
	cUIButton*              m_pUIButton_MRight;
	cUITextView*            m_pUIText_MID;

	cUIButton*              m_pUIButton_SLeft;
	cUIButton*              m_pUIButton_SRight;
	cUITextView*            m_pUIText_SID;
	// <<

	// >> : Object ID에 대한 인덱스 값
	int						m_nObject_LIndex;
	int						m_nObject_MIndex;
	int						m_nObject_SIndex;

	int						m_nPage;
	// << : 

	// >> : RadioButton에 대한 변수 & construct
	cRadioButton*			m_pRadioButton_Object;
	// << :

	// >> : Construct에 관한 변수
	cConstruct*				m_pConstruct;
	vector<cConstruct*>		m_vecConstruct;
	// << :

	// >> : SkyBox에 관한 변수
	cSkyBox*				m_pSkyBox;
	// <<

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update(float deltaTime);
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetOption();
	void MoveStandardPos(float deltaTime);

	void Setup_UI();
	void Update_UI();
	void Render_UI(LPD3DXSPRITE pSprite);

	void Update_Object();
	void Update_L_Object();
	void Update_M_Object();
	void Update_S_Object();
	void Render_Object();

	void Update_MapBrush();
	void Update_Menu();

	void Setup_DirLight();

	void SaveMap();
	void LoadMap();

	void Setup_SkyBox();
};

