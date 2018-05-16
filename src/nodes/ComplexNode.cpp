#include "include/nodes/ComplexNode.h"

ComplexNode::ComplexNode():Node(CPLX_G,60,50,Qt::white,2){
}

void ComplexNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	Node::paint(painter,option,widget);
	painter->drawText(boundingRect().center()-QPoint(24,-2),"Complex");
}

data_t ComplexNode::eval(){
	if(validVal) return val;
	val=cplx(iNodes[0]->eval(),iNodes[1]->eval());
	validVal=true;
	return val;
}
