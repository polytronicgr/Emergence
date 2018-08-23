#include "ConditionPlugin.h"
#include "IfNode.h"

void ConditionPlugin::updateUI(Ui::MainWindow*ui) const{
	QAction* ifAction= new QAction(QIcon(":/if.png"),"Condition");

	Workspace* ws=(Workspace*)ui->workspace->scene();
	connect(ifAction,&QAction::triggered,ws,[=]{ws->addNode(Node::nodeMalloc("if"));});

	ui->menuInsert->addAction(ifAction);
}

void ConditionPlugin::addNodes()const{
	Node::makeNodeMethods["if"] = &IfNode::makeNode;

	NodeBox::addTool("if","Condition",QIcon(":/if.png"));
}
