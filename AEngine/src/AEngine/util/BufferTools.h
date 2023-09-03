#pragma once
namespace AEngine {

    /**
     * @brief Converts a given set of arrays into a single FAT array (FAT Buffer). Expects the parameters to be of the same Base type.
     * @param _numArrays The number of arrays being processed.
     * @param ... any amount of arrays (Buffers)
     * @return Returns a void pointer to the fat array (FAT Buffer) containing all the elements of the provided arrays.
    */
    void* MakeFatArray(int _numArrays, ...) { }


}
