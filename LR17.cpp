#include "pch.h"

using namespace System;
using namespace System::IO;
namespace ConsoleApplication2
{
	public ref class Program
	{
	public:
		static void Main()
		{
			Console::WriteLine("\nСписок каталогов в текущем каталоге (C:\\Users\\Administrator\\Desktop\\Test):\n");
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\Administrator\\Desktop\\Test"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
			}
			Console::WriteLine("\nСписок файлов в текущем каталоге (C:\\Users\\Administrator\\Desktop\\Test):\n");
			for each (String ^ entry in Directory::GetFiles("C:\\Users\\Administrator\\Desktop\\Test"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}
			Console::WriteLine("\nСписок каталогов для каждего входящего в текущий каталог (C:\\Users\\Administrator\\Desktop\\Test) каталога:\n");
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\Administrator\\Desktop\\Test"))
			{
				for each (String ^ entry1 in Directory::GetDirectories((gcnew DirectoryInfo(entry))->FullName + "\\")) {
					DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry1));
				}
				
			}
			Console::WriteLine("\nСписок файлов для каждего входящего в текущий каталог (C:\\Users\\Administrator\\Desktop\\Test) каталога:\n");
			for each (String ^ entry in Directory::GetDirectories("C:\\Users\\Administrator\\Desktop\\Test"))
			{
				for each (String ^ entry1 in Directory::GetFiles((gcnew DirectoryInfo(entry))->FullName + "\\"))
				{
					DisplayFileSystemInfoAttributes(gcnew FileInfo(entry1));
				}
			}
		}
		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			String^ entryType = "Файл";
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Каталог";
			}
			Console::WriteLine("{0,-7} {1,-60} {2,-20:D} {3,-25:D}", entryType, fsi->FullName, fsi -> CreationTime, fsi->LastAccessTime);
		}
	};
};
int main()
{
	Console::WriteLine("---------------------------------------------------------------------------------------------------------------------------------------------");
	Console::WriteLine(" Тип                Полный путь                                        Дата создания       Дата изменения\n");
	Console::WriteLine("---------------------------------------------------------------------------------------------------------------------------------------------");
	ConsoleApplication2::Program::Main();

}
