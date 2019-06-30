#pragma once
#include "stdafx.h"
#include "06.h"
INT_PTR CALLBACK ViewDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DiagramDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK AddDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ColorDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

struct Item
{
	std::string code;
	std::string name;
	std::string quantity;
	std::string age;
	std::string unitPrice;
	std::string date;
	std::string provider;

	std::string line;

	Item() {}

	bool operator<(const Item& T)const
	{
		if (code == T.code)
			return (name < T.name);
		return code < T.code;
	}
	void doOneString()
	{
		line = code;
		for (int i = code.size(); i < 6; ++i)
			line += ' ';
		line += name;
	}
};

class _Data // Model
{
private:

	std::vector<Item> Toys;
	int nItems = 0;

	HINSTANCE& hInst;

public:

	_Data(HINSTANCE& hInst): hInst(hInst) {}
	HINSTANCE& get_hInst() { return hInst; }
	int get_nItems()const { return nItems; }
	void set_nItems(int n) { nItems = n; }
	void Dec_nItems() { --nItems; }
	void Inc_nItems() { ++nItems; }
	Item& operator[](int i) { return Toys[i]; }
	void push_back() { Toys.push_back(Item()); }
	void erase(int i) { Toys.erase(Toys.begin() + i); }
	void sort() { std::sort(Toys.begin(), Toys.end()); }
	void clear() { Toys.clear(); }

};

class _View // View 1
{
private:
	_Data & Data;

public:

	_View(_Data& Data) : Data(Data) {}
	void Show(HWND hWnd)
	{
		DialogBox(Data.get_hInst(), MAKEINTRESOURCE(IDD_VIEWBOX), hWnd, ViewDlgProc);
	}


};



class _DiagramView // View 2
{
private:
	_Data & Data;

public:

	_DiagramView(_Data& Data): Data(Data) {}

	void Show(HWND hWnd)
	{
		if (Data.get_nItems())
			DialogBox(Data.get_hInst(), MAKEINTRESOURCE(IDD_DIAGRAM), hWnd, DiagramDlgProc);
		else
			MessageBox(hWnd, "Не возможно отобразить диаграмму. Нет данных", "Ошибка", MB_OK);
	}
	void Paint(HWND hDlg, COLORREF current_color)
	{
		HBRUSH hBrush = CreateSolidBrush(current_color);
		int	x_max = 0,
			y_max = 4 * Data.get_nItems() + 2;
		for (int i = 0; i < Data.get_nItems(); ++i)
			if (stoi(Data[i].quantity) > x_max)
				x_max = stoi(Data[i].quantity);
		RECT rect;
		GetClientRect(hDlg, &rect);
		int width = rect.right - rect.left,
			height = rect.bottom - rect.top;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		SelectObject(hdc, hBrush);

		//Новые координаты
		SetMapMode(hdc, MM_ANISOTROPIC);
		SetWindowExtEx(hdc, x_max * 3 / 2, y_max * 6 / 5, NULL);
		SetViewportExtEx(hdc, rect.right, -rect.bottom, NULL);
		SetViewportOrgEx(hdc, width / 5, height * 9 / 10, NULL);
		//Оси
		MoveToEx(hdc, x_max, 0, NULL);
		LineTo(hdc, 0, 0);
		LineTo(hdc, 0, y_max);
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, x_max * 9 / 10, 0, "Кол-во", 6);
		TextOut(hdc, -x_max / 4, y_max, "Название", 8);

		for (int i = 0; i < Data.get_nItems(); ++i)
		{
			TextOut(hdc, -x_max / 4, 3 + 4 * i, Data[i].name.c_str(), Data[i].name.size());
			Rectangle(hdc, 0, 4 + 4 * i, stoi(Data[i].quantity), 1 + 4 * i);
			TextOut(hdc, stoi(Data[i].quantity), 3 + 4 * i, Data[i].quantity.c_str(), Data[i].quantity.size());
		}
		EndPaint(hDlg, &ps);
		DeleteObject(hBrush);
	}

};



class _Controller 
{
private:

	_Data & Data;

	std::ifstream fin;
	std::string finName;
	std::ofstream fout;
	std::string foutName;

public:

	_Controller(_Data& Data): Data(Data) {}
	const std::string& get_finName()const { return finName; }
	const std::string& get_foutName()const { return foutName; }

	void OutputData()
	{
		if (Data.get_nItems())
		{
			fout.open(foutName);
			fout.seekp(fout.beg);
			fout << Data[0].name << ' ' << Data[0].code << ' ' << Data[0].quantity << ' '
				<< Data[0].unitPrice << ' ' << Data[0].age << ' ' << Data[0].date << ' ' << Data[0].provider;
			for (int i = 1; i < Data.get_nItems(); ++i)
				fout << std::endl << Data[i].name << ' ' << Data[i].code << ' ' << Data[i].quantity << ' '
				<< Data[i].unitPrice << ' ' << Data[i].age << ' ' << Data[i].date << ' ' << Data[i].provider;
		}
	}

	void File_Open(OPENFILENAME& ofn, HWND& hWnd)
	{
		fin.close();
		fin.open(ofn.lpstrFile);
		finName = ofn.lpstrFile;
		foutName = ofn.lpstrFile;
		RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);

		//Считювание из файла
		if (fin.is_open())
		{
			Data.clear();
			Data.set_nItems(0);
			int i = 0;
			while (!fin.eof())
			{
				Data.push_back();
				fin >> Data[i].name >> Data[i].code >> Data[i].quantity >> Data[i].unitPrice
					>> Data[i].age >> Data[i].date >> Data[i].provider;
				Data[i].doOneString();
				++i;
			}
			Data.set_nItems(i);
			Data.sort();
		}
	}

	void File_Close(OPENFILENAME& ofn, HWND& hWnd)
	{
		if (fin.is_open())
		{
			fin.close();
			finName.clear();
			RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
		}
	}

	void File_Save()
	{
		if (!foutName.empty())
		{
			OutputData();
		}
	}

	void File_Save_as(OPENFILENAME& ofn, HWND& hWnd)
	{
		foutName = ofn.lpstrFile;
		RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
		OutputData();
	}

	void Choose_color(HWND hWnd)
	{
		DialogBox(Data.get_hInst(), MAKEINTRESOURCE(IDD_COLOR), hWnd, ColorDlgProc);
	}

	void AddItem(HWND hDlg)
	{
		bool dlgYes = (BOOL)DialogBox(Data.get_hInst(), MAKEINTRESOURCE(IDD_ADDBOX), hDlg, AddDlgProc);
		if (dlgYes)
		{
			SendDlgItemMessage(hDlg, IDC_LIST, LB_ADDSTRING, 0, (LPARAM)Data[Data.get_nItems() - 1].line.c_str());
			Data.sort();
		}
	}

	void DeleteItem(HWND hDlg)
	{
		int iCurListItem = (int)SendDlgItemMessage(hDlg, IDC_LIST, LB_GETCURSEL, NULL, NULL);
		if (iCurListItem != LB_ERR) {
			Data.erase(iCurListItem);
			SendDlgItemMessage(hDlg, IDC_LIST, LB_DELETESTRING, iCurListItem, 0);
			SetDlgItemText(hDlg, IDC_EDIT1, "");
			SetDlgItemText(hDlg, IDC_EDIT2, "");
			SetDlgItemText(hDlg, IDC_EDIT3, "");
			SetDlgItemText(hDlg, IDC_EDIT4, "");
			SetDlgItemText(hDlg, IDC_EDIT5, "");
			Data.Dec_nItems();
		}
		else
			MessageBox(hDlg, "Select the list item", "Error", MB_OK);
	}
	
	void ItemClick(HWND hDlg)
	{
		int iCurListItem = (int)SendDlgItemMessage(hDlg, IDC_LIST, LB_GETCURSEL, NULL, NULL);
		SendDlgItemMessage(hDlg, IDC_LIST, LB_GETTEXT, iCurListItem, (LPARAM)Data[iCurListItem].line.c_str());
		SetDlgItemText(hDlg, IDC_EDIT1, Data[iCurListItem].quantity.c_str());
		SetDlgItemText(hDlg, IDC_EDIT2, Data[iCurListItem].unitPrice.c_str());
		SetDlgItemText(hDlg, IDC_EDIT3, Data[iCurListItem].age.c_str());
		SetDlgItemText(hDlg, IDC_EDIT4, Data[iCurListItem].date.c_str());
		SetDlgItemText(hDlg, IDC_EDIT5, Data[iCurListItem].provider.c_str());
	}

	
};
