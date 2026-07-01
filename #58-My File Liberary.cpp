#pragma once
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
namespace MyFile
{
	void SaveVectorInFile(string FilePath, vector<string>VectorToSave)
	{
		fstream File;
		File.open(FilePath, ios::out);
		if (File.is_open())
		{
			for (string& Line : VectorToSave)
			{
				if (Line != "")
				{
					File << Line << endl;
				}
			}
			File.close();
		}
	}
	void LoadDataFromFileToVector(string FilePath, vector<string>& VectorToLoad)
	{
		fstream File;
		File.open(FilePath, ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				VectorToLoad.push_back(Line);
			}
			File.close();
		}

	}
	void DeleteFromFile(string FilePath, string StringToDelete)
	{
		vector<string>Temp;
		LoadDataFromFileToVector(FilePath, Temp);

		for (string& line : Temp)
		{
			if (line == StringToDelete)
			{
				line = "";
			}
		}
		SaveVectorInFile(FilePath, Temp);


	}
	void PrintFileData(string FilePath)
	{
		fstream File;
		File.open(FilePath, ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				cout << Line << endl;
			}
			File.close();
		}

	}
	void AddStringInFile(string FilePath, string StringToAdd)
	{
		fstream File;
		File.open(FilePath, ios::out | ios::app);
		if (File.is_open())
		{
			File << StringToAdd << endl;
		}
	}
	void UpdateRecordInFile(string FilePath, string StringToUpdate, string Update)
	{
		vector<string>Temp;
		LoadDataFromFileToVector(FilePath, Temp);
		for (string& line : Temp)
		{
			if (line == StringToUpdate)
			{
				line = Update;
			}
		}
		SaveVectorInFile(FilePath, Temp);
	}
}
