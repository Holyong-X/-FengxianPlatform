#pragma once

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum SUPERMAP_API PlaneClipMode
			{
				CLIP_NOTHING = 0,   //不裁剪
				CLIP_BEHIND_ANY_PLANE = 1,  //裁剪掉位于任意裁剪面后面的部分
				CLIP_BEHIND_ALL_PLANE = 2, //裁剪掉位于所有裁剪面后面的部分
				ONLY_KEEP_LINE = 3, // 只保留裁线，裁剪掉其他部分
			};

			enum SUPERMAP_API BoxClipPart
			{
				ClipNothing = 0,    //不裁剪
				ClipOuter = 1,      //裁剪掉盒子外部的部分
				ClipInner = 2,      //裁剪掉盒子内部的部分
			};
		}
	}
}