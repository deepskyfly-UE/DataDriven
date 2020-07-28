// Copyright 2018 Jianzhao Fu. All Rights Reserved.
#include "ExcelWorkbook.h"
//#include "AllowWindowsPlatformTypes.h"
#ifdef WIN32
#include "Windows/WindowsHWrapper.h"
//#include "HideWindowsPlatformTypes.h"
#endif

#include "Misc/Paths.h"
#include "ExcelWorksheet.h"
#include "LogTypes.h"
#include "Engine.h"
#include "DirectExcelLibrary.h"


bool UExcelWorkbook::StartWatch(const UObject* WorldContextObject, FExcelWorkbookChangedDelegate onChanged, bool autoReload /*= true*/, float rate/*=1.f*/)
{
#ifdef WIN32

	//wchar_t watchDirectory[512] = { 0 };
	//MultiByteToWideChar(CP_ACP, 0, (char*)*mPath, strlen((char*)*mPath), watchDirectory, sizeof(watchDirectory) / sizeof(wchar_t));
	FString path = FPaths::GetPath(mPath);
	const wchar_t* p = *path;

	mFindHandle = ::FindFirstChangeNotification(p, 0, FILE_NOTIFY_CHANGE_LAST_WRITE);
	if (INVALID_HANDLE_VALUE == mFindHandle)
	{
		DWORD errorCode = GetLastError();
		UE_LOG(LogDirectExcel, Error, L"%d", errorCode);
		return false;
	}

	UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	world->GetTimerManager().SetTimer(mWatchTimer, [this, WorldContextObject, onChanged, autoReload]
	{
		DWORD dwWait = ::WaitForSingleObject(mFindHandle, 0);
		UE_LOG(LogDirectExcel, Warning, TEXT("Watch result:%d."), dwWait);
		if (dwWait == WAIT_FAILED)
		{
			DWORD errorCode = GetLastError();
			UE_LOG(LogDirectExcel, Error, L"%d", errorCode);
			StopWatch(WorldContextObject);
			return;
		}

		if (WAIT_OBJECT_0 == dwWait)
		{
			bool isOpen = true;
			if (autoReload)
			{
				isOpen = Reload();
			}

			if (isOpen)
			{
				onChanged.ExecuteIfBound(this);
			}
			else
			{
				onChanged.ExecuteIfBound(nullptr);
			}

			if (!::FindNextChangeNotification(mFindHandle))
			{
				::FindCloseChangeNotification(mFindHandle);
				mFindHandle = NULL;
				UE_LOG(LogDirectExcel, Warning, TEXT("Lost watch."));
			}
		}

	}, rate, true);
#endif

	return true;

}

bool UExcelWorkbook::StopWatch(const UObject* WorldContextObject)
{
#ifdef WIN32

	if (mWatchTimer.IsValid() && WorldContextObject != nullptr)
	{
		UWorld* world = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
		world->GetTimerManager().ClearTimer(mWatchTimer);
	}

	if (INVALID_HANDLE_VALUE != mFindHandle)
	{
		::FindCloseChangeNotification(mFindHandle);
		mFindHandle = NULL;
	}
#endif
	return true;
}



