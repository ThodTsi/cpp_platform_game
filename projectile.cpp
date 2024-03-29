#pragma once
#include "box.h"
#include <sgg/graphics.h>
#include "gamestate.h"
//#include "level.h"
#include "gameobject.h"
#include "projectile.h"
#include "util.h"
#include "iostream"
#include "player.h"
using namespace std;


void Projectile::init(float x,float y) {
	setPosX(x);
	setPosY(y);
	m_brush_projectile.fill_opacity = 1.0f;
	m_brush_projectile.outline_opacity = 0.0f;
	m_brush_projectile.texture = m_state->getFullAssetPath("ribbon.png");
	
}

void Projectile::draw() {
		//graphics::drawRect(posX(), posY(), 1.0f, 1.0f, m_brush_projectile);
		if (left){
			graphics::drawRect(m_state->getCanvasHeight() * 0.5f - i, m_state->getCanvasWidth() * 0.5f, 0.3f, 0.3f, m_brush_projectile);
			i += 0.1f;
		}
		else {
			graphics::drawRect(m_state->getCanvasHeight() * 0.5f + i, m_state->getCanvasWidth() * 0.5f, 0.3f, 0.3f, m_brush_projectile);
			i += 0.1f;
		}
		if (m_state->m_debug_mode) {
			debugDrawProj();
		}
		
}

void Projectile::update(float ms){
	if (left) {
		setPosX(posX() - speed);
	}else{
		setPosX(posX() + speed);
	}
	GameObject::update(ms);
}

void Projectile::debugDrawProj() {
	graphics::Brush debug_brush;
	SETCOLOR(debug_brush.fill_color, 1, 0.3f, 0);
	SETCOLOR(debug_brush.outline_color, 1, 0.1f, 0);
	debug_brush.fill_opacity = 0.1f;
	debug_brush.outline_opacity = 1.0f;
	//float x = posX() + m_state->m_global_offset_x;
	//float y = posY() + m_state->m_global_offset_y;
	//graphics::drawRect(x, y, m_width, m_height, debug_brush);
	char s[20];
	sprintf_s(s, "(%5.2f, %5.2f", m_pos_x, m_pos_y);
	SETCOLOR(debug_brush.fill_color, 1, 0, 0);
	debug_brush.fill_opacity = 1.0f;
	float drawX, drawY;
	if (left) {
		// Adjust the position based on the projectile's position and direction
		drawX = posX() - i;
		drawY = posY();
	}
	else {
		// Adjust the position based on the projectile's position and direction
		drawX = posX() + i;
		drawY = posY() - 0.6f;
	}
	graphics::drawText(drawX + m_state->m_global_offset_x, drawY + m_state->m_global_offset_y, 0.15f, s, debug_brush);
}


