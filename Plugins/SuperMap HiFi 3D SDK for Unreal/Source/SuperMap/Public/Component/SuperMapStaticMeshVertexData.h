#pragma once

#include "CoreMinimal.h"
#include "Containers/DynamicRHIResourceArray.h"
#include "Rendering/StaticMeshVertexDataInterface.h"

template< typename ElementType, Gameuint Alignment = DEFAULT_ALIGNMENT>
class TSuperMapResourceArray : public TResourceArray<ElementType, Alignment>
{
public:
	TSuperMapResourceArray(Gamebool InNeedsCPUAccess = false) : TResourceArray<ElementType, Alignment>(InNeedsCPUAccess)
	{

	}

	/*virtual Gamevoid Discard()
	{
		if (!GetAllowCPUAccess())
		{
			this->Empty();
		}
	}*/
};


/** The implementation of the static mesh vertex data storage type. */
template<typename VertexDataType>
class TSuperMapStaticMeshVertexData :
	public FStaticMeshVertexDataInterface
{
	using FSuperMapVertexResourceArray = TSuperMapResourceArray<VertexDataType, VERTEXBUFFER_ALIGNMENT>;
	FSuperMapVertexResourceArray Data;
public:

	/**
	* Constructor
	* @param InNeedsCPUAccess - true if resource array data should be CPU accessible
	*/
	TSuperMapStaticMeshVertexData(Gamebool InNeedsCPUAccess = false)
		: Data(InNeedsCPUAccess)
	{
	}

	/**
	* Resizes the vertex data buffer, discarding any data which no longer fits.
	*
	* @param NumVertices - The number of vertices to allocate the buffer for.
	* @param BufferFlags - Flags to define the expected behavior of the buffer
	*/
	Gamevoid ResizeBuffer(Gameuint NumVertices, EResizeBufferFlags BufferFlags = EResizeBufferFlags::None) override
	{
		if ((Gameuint)Data.Num() < NumVertices)
		{
			// Enlarge the array.
			if (!EnumHasAnyFlags(BufferFlags, EResizeBufferFlags::AllowSlackOnGrow))
			{
				Data.Reserve(NumVertices);
			}

			Data.AddUninitialized(NumVertices - Data.Num());
		}
		else if ((Gameuint)Data.Num() > NumVertices)
		{
			// Shrink the array.
			Gamebool AllowShinking = !EnumHasAnyFlags(BufferFlags, EResizeBufferFlags::AllowSlackOnReduce);
			Data.RemoveAt(NumVertices, Data.Num() - NumVertices, AllowShinking);
		}
	}

	Gamevoid Empty(Gameuint NumVertices) override
	{
		Data.Empty(NumVertices);
	}

	Gamebool IsValidIndex(Gameuint Index) override
	{
		return Data.IsValidIndex(Index);
	}

	/**
	* @return stride of the vertex type stored in the resource data array
	*/
	Gameuint GetStride() const override
	{
		return sizeof(VertexDataType);
	}
	/**
	* @return uint8 pointer to the resource data array
	*/
	uint8* GetDataPointer() override
	{
		return (uint8*)Data.GetData();
	}

	/**
	* @return resource array interface access
	*/
	FResourceArrayInterface* GetResourceArray() override
	{
		return &Data;
	}

	const FResourceArrayInterface* GetResourceArray() const
	{
		return &Data;
	}

	/**
	* Serializer for this class
	*
	* @param Ar - archive to serialize to
	* @param B - data to serialize
	*/
	Gamevoid Serialize(FArchive& Ar, Gamebool bForcePerElementSerialization = false) override
	{
		Data.FSuperMapVertexResourceArray::BulkSerialize(Ar, bForcePerElementSerialization);
	}
	/**
	* Assignment. This is currently the only method which allows for
	* modifying an existing resource array
	*/
	Gamevoid Assign(const TArray<VertexDataType>& Other)
	{
		ResizeBuffer(Other.Num());
		if (Other.Num())
		{
			memcpy(GetDataPointer(), &Other[0], Other.Num() * sizeof(VertexDataType));
		}
	}

	/**
	* Helper function to return the amount of memory allocated by this
	* container.
	*
	* @returns Number of bytes allocated by this container.
	*/
	SIZE_T GetResourceSize() const override
	{
		return Data.GetAllocatedSize();
	}

	/**
	* Helper function to return the number of elements by this
	* container.
	*
	* @returns Number of elements allocated by this container.
	*/
	virtual Gameint Num() const override
	{
		return Data.Num();
	}

	Gamebool GetAllowCPUAccess() const override
	{
		return Data.GetAllowCPUAccess();
	}

	Gamevoid OverrideFreezeSizeAndAlignment(int64& Size, Gameint& Alignment) const override
	{
		Size = sizeof(*this);
	}
};
