#pragma once

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum SUPERMAP_API PlaneClipMode
			{
				CLIP_NOTHING = 0,   //���ü�
				CLIP_BEHIND_ANY_PLANE = 1,  //�ü���λ������ü������Ĳ���
				CLIP_BEHIND_ALL_PLANE = 2, //�ü���λ�����вü������Ĳ���
				ONLY_KEEP_LINE = 3, // ֻ�������ߣ��ü�����������
			};

			enum SUPERMAP_API BoxClipPart
			{
				ClipNothing = 0,    //���ü�
				ClipOuter = 1,      //�ü��������ⲿ�Ĳ���
				ClipInner = 2,      //�ü��������ڲ��Ĳ���
			};
		}
	}
}