// Distributed under the MIT License (MIT) (see accompanying LICENSE file)
#pragma once

#include "ImGuiTheming.generated.h"

struct ImFontAtlas;

enum class EIMTheme : uint8
{
	Black,
	Dark,
	Grey,
	Light,
	Blue,
	ClassicLight,
	ClassicDark,
	Classic,
	Cherry
};

enum class EIMThemeFont : uint8
{
	Default		   = 0,
	Roboto		   = 1,
	KarlaRegular   = 2,
	CousineRegular = 3,
};
constexpr uint8 EIMThemeFont_MaxCount = (uint8) EIMThemeFont::CousineRegular + 1;

USTRUCT()
struct IMGUI_API FImGuiThemeStyle
{
	GENERATED_BODY()

	EIMTheme	   theme							= EIMTheme::Dark;
	EIMThemeFont   themeFont						= EIMThemeFont::KarlaRegular;
	float		   fontSize							= 16.0f;
    ImFontAtlas*   fontAtlas = nullptr;

	void OnInit(ImFontAtlas& InFontAtlas);
	void OnDestroy();
	void SetImGuiStyle();
	static void SetTheme(EIMTheme);
};