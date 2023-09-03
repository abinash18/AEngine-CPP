#pragma once
#include <glad/glad.h>

namespace AEngine {
    enum class AEDataType {
        NONE,
        FLOAT,
        FLOAT2,
        FLOAT3,
        FLOAT4,
        MAT3,
        MAT4,
        INT,
        INT2,
        INT3,
        INT4,
        BOOL
    };

    static uint32_t AETypeSize(AEDataType _type) {
        switch (_type) {
            case AEDataType::FLOAT:
                return 4;
            case AEDataType::FLOAT2:
                return 4 * 2;
            case AEDataType::FLOAT3:
                return 4 * 3;
            case AEDataType::FLOAT4:
                return 4 * 4;
            case AEDataType::MAT3:
                return 4 * 3 * 3;
            case AEDataType::MAT4:
                return 4 * 4 * 4;
            case AEDataType::INT:
                return 4;
            case AEDataType::INT2:
                return 4 * 2;
            case AEDataType::INT3:
                return 4 * 3;
            case AEDataType::INT4:
                return 4 * 4;
            case AEDataType::BOOL:
                return 1;
        }
        AE_CORE_ASSERT(0, "UNKNOWN DATATYPE: {0}");
        return 0;
    };

    static uint32_t AETypeElementCount(AEDataType _type) {
        switch (_type) {
            case AEDataType::FLOAT:
                return 1;
            case AEDataType::FLOAT2:
                return 2;
            case AEDataType::FLOAT3:
                return 3;
            case AEDataType::FLOAT4:
                return 4;
            case AEDataType::MAT3:
                return 3 * 3;
            case AEDataType::MAT4:
                return 4 * 4;
            case AEDataType::INT:
                return 1;
            case AEDataType::INT2:
                return 2;
            case AEDataType::INT3:
                return 3;
            case AEDataType::INT4:
                return 4;
            case AEDataType::BOOL:
                return 1;
        }
        AE_CORE_ASSERT(0, "UNKNOWN DATATYPE: {0}");
        return 0;
    }

    static GLenum AETypeToGLType(AEDataType _type) {

        switch (_type) {
            case AEDataType::FLOAT:
            case AEDataType::FLOAT2:
            case AEDataType::FLOAT3:
            case AEDataType::FLOAT4:
            case AEDataType::MAT3:
            case AEDataType::MAT4:
                return GL_FLOAT;
            case AEDataType::INT:
            case AEDataType::INT2:
            case AEDataType::INT3:
            case AEDataType::INT4:
                return GL_INT;
            case AEDataType::BOOL:
                return GL_BOOL;
        }

        AE_CORE_ASSERT(0, "UNKNOWN DATATYPE: {0}");
        return 0;
    };

}
