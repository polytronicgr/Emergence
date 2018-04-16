#include "include/nodes/ConstNode.h"

ConstNode::ConstNode(double v):Node(DOUBLE_G,50,50,QColor(255,255,180)){
	val=v;
}
ConstNode::ConstNode(uint v):Node(COLOR_G,50,50,QColor(v)){
	val=v;
}

void ConstNode::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget*widget){
	Node::paint(painter,option,widget);
	switch(val.t){
	case TypeEnum::DOUBLE:
		painter->drawText(boundingRect().center()-QPoint(12,-2),QString::number(val.d));
		break;
	case TypeEnum::COLOR:
		painter->drawText(boundingRect().center()-QPoint(16,-2),"Color");
		break;
	default:
		break;
	}
}

void ConstNode::contextMenuEvent(QGraphicsSceneContextMenuEvent* event){
	menu=new QMenu;
	switch(val.t){
	case TypeEnum::DOUBLE:
		connect(menu->addAction(QString("Change number")), &QAction::triggered,this,&ConstNode::changeNumber);
		break;
	case TypeEnum::COLOR:
		connect(menu->addAction(QString("Change color")), &QAction::triggered,this,&ConstNode::changeColor);
		break;
	default:
		break;
	}
	Node::contextMenuEvent(event);
}

data_t ConstNode::eval(){
	if(!validVal) validVal=true;
	return val;
}

void ConstNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*){
	switch(val.t){
	case TypeEnum::DOUBLE:
		changeNumber();
		break;
	case TypeEnum::COLOR:
		changeColor();
		break;
	default:
		break;
	}
}

void ConstNode::changeColor(){
	QColor c =QColorDialog::getColor(Qt::white,(QWidget*)parentWidget());
	if(c.isValid()){
		val.u=c.rgba();
		color=c;
		updateOutputVal();
		update();
		emit notifyRA();
	}
}

void ConstNode::changeNumber(){
	bool ok;
	double d =QInputDialog::getDouble((QWidget*)parentWidget(),"Choose Number","",0,-2147483647,2147483647,3,&ok);
	if(ok){
		val.d=d;
		updateOutputVal();
		update();
		emit notifyRA();
	}
}