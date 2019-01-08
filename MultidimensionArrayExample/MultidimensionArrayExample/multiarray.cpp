#include "multiarray.h"


//---------- CONSTRUCTOR   MultiArray ----------

MultiArray :: MultiArray()
{
    qDebug()<<"CONSTRUCTOR   MultiArray";
}

//---------- DESTRUCTOR   ~MultiArray ----------

MultiArray :: ~MultiArray(){
    qDebug()<<"DESTRUCTOR   ~MultiArray";
    delete nodeArray;
}

//---------- dimensionTheArray ----------

void MultiArray :: dimensionTheArray(const uint x, const uint y, const uint z){
    dimX = x;
    dimY = y;
    dimZ = z;

    maxX = dimX - 1;
    maxY = dimY - 1;
    maxZ = dimZ - 1;

    int nArrayBytes = x * y * z * sizeof(NodeType);
    nodeArray = new NodeType[nArrayBytes];
}

//---------- setNode ----------

void MultiArray :: setNode(uint x, uint y, uint z, NodeType* node){
    nodeArray[index(x,y,z)] = *node;
}

//---------- getNode ----------

NodeType MultiArray :: getNode(uint x, uint y, uint z){
    return nodeArray[index(x,y,z)];
}

//---------- index ----------

uint  MultiArray :: index(uint x, uint y, uint z){

    if ((x > maxX) || (y > maxY) || (z > maxZ)){
        QString errorStr = "MultiArray :: index";
        errorStr.append("\nIndex out of range.");
        QMessageBox msgBox;
        msgBox.setText(errorStr);
        msgBox.exec();
        return 0;
    }//if

    return (x + y * maxY + z * maxY * maxZ);
}
