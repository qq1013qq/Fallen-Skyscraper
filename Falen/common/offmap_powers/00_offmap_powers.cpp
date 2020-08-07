offmap_china = {
	name = china_china
	window_name = domestic_offmaps_window
	button_name = icon_offmaps_entry
	currency_name = TXT_GRACE
	currency_gain = monthly_grace
	currency_reset_on_dynasty_change = yes
	holder_title = title_china_emperor			# minor title used to identify a character as holder of this offmap power
	governor_title = e_china_west_governor
	tier = emperor
	non_aggression_modifier = peace_deal_with_china
	coa_religion = sanminzhuyi
	government = confucian_bureaucracy
	beginning_of_history = 1925.7.1 # 광저우 국민정부 수립부터
	sound = china_interaction_interface
	display_trigger = {
		always = yes
	}
	policies = {
		china_open
		china_isolationist
		china_expansionist
	}
	statuses = {
		china_stable
		china_unrest
		china_civil_war
	#	china_mongol_invasion
	#	china_jurchen_invasion
		china_famine
		china_plague
		china_golden_age
	}
	buttons = {
		offmap_gifts = {
			is_active_trigger = {
				china_offmap_tribute_decisions_enabled_trigger = yes
			}
		}
		offmap_boons = {
			is_active_trigger = {
				china_offmap_boon_decisions_enabled_trigger = yes
			}
		}
		offmap_hostility = {
			is_active_trigger = {
				china_offmap_hostile_decisions_enabled_trigger = yes
			}
			display_trigger = {
				NOT = { offmap_china = { offmap_ruler = { dynasty = FROM } } }
			}
		}
		offmap_hostility2 = {
			display_trigger = {
				always = no
			}
		}
	}
	
	#These conditions only effect the appearance of the button, it does not actually disable them from being clickable. The same triggers are used in all tribute/boon decisions respectively
	
	icon_triggers = {
		china_physician_cd = {
			frame = 9
			trigger = {
				hidden_tooltip = {
					has_character_flag = chinese_grace_physician_sent
				}
			}
		}
		china_raid_cd = {
			frame = 8
			right = yes	
			trigger = {
				hidden_tooltip = {
					has_character_modifier = china_raid_grace_cd
				}
			}
		}
		china_famine_cd = {
			frame = 7
			trigger = {
				hidden_tooltip = {
					has_character_modifier = china_send_relief
				}
			}
		}
		china_tributary_cd = {
			frame = 6
			trigger = {
				hidden_tooltip = {
					has_character_modifier = chinese_grace_tributary_timer
				}
			}
		}
		china_boon_cd = {
			frame = 5
			right = yes	
			trigger = {
				hidden_tooltip = {
					has_character_modifier = jd_china_boon_cd
				}
			}
		}
		china_commander_cd = {
			frame = 4
			trigger = {
				hidden_tooltip = {
					has_character_modifier = chinese_grace_send_commander_timer
				}
			}
		}
		china_eunuch_cd = {
			frame = 3
			trigger = {
				hidden_tooltip = {
					has_character_modifier = chinese_grace_send_eunuch_timer
				}
			}
		}
		china_concubine_cd = {
			frame = 2
			trigger = {
				hidden_tooltip = {
					has_character_modifier = chinese_grace_send_concubine_timer
				}
			}
		}
		china_gift_cd = {
			frame = 1
			trigger = {
				hidden_tooltip = {
					has_character_modifier = chinese_grace_send_gift_timer
				}
			}
		}
	}
	
	monthly_currency_gain = {
		offmap_same_dynasty = {
			value = 10
			offmap_china = { offmap_ruler = { dynasty = FROM } }
		}
		offmap_war_with_me = {
			value = -10
			war_with = FROM
		}
		offmap_likes_me = {
			value = 1
			FROM = { is_liked_by_China_trigger = yes }
			is_within_diplo_range = FROM
		}
		offmap_likes_tributaries = {
			value = 2
			offmap_china = {			
				offmap_has_like = likes_tributaries
			}
			FROM = {
				is_tributary = {
					type = offmap
				}
			}
		}
		vassal_of_WP = {
			value = 2
			FROM = {
				liege = {
					has_landed_title = e_china_west_governor
				}
			}
		}
		offmap_same_culture_and_religion = {
			value = 2
			offmap_ruler = {
				culture = FROM
				religion = FROM
			}
			is_within_diplo_range = FROM
		}
	}
	
	temple_names = {
		{} # 봉건잔재인 묘호는 쓰지않는다
		{}
	}
	holder_succession = {
		is_female = {					# chances of getting a female holder, as a percentage: if the total is >= 100, the new holder will always be female. If the total is <= 0, the new holder will always be male
			value = 5
			additive_modifier = {
				value = 45
				has_game_rule = {
					name = gender
					value = all
				}
			}
		}
		culture = {
	
			han = { # default culture for new emperor
				value = 99 # if any other value reaches 100, it will be picked instead
			}
			FROM = { # default culture for new emperor
								# the left side here (and for culture, religion, graphical_culture and dynasty) can be a right hand side value (FROM, ROOT, a culture name, etc). and the right hand side / inside the brackets is a standard MTTH evaluation. Only the one with the highest weight will be used. If there's a tie, one of the tied values is picked at random
				value = 0
				additive_modifier = { #the new emperor will keep current culture if things are great
					value = 100
					#china_is_fine_trigger = yes
					FROM = { culture_scope = { always = yes } } # Essentially a check that the previous emperor actually exists
				}
			}
			red_panda = {
				value = 0
				additive_modifier = {
					has_alternate_start_parameter = { key = special_culture value = animal_world }
					value = 100
				}
			}
		}

		graphical_culture = { 
			FROM = {
				value = 100
			}
		}

		religion = {
			sanminzhuyi = { # default religion for new emperor
				value = 99 # if any other value reaches 100, it will be picked instead (unless equal, then it will randomize)
			}
			FROM = {
				value = 0
				additive_modifier = { # the new emperor will keep current religion if things are great
					value = 100
					#china_is_fine_trigger = yes
					FROM = { religion_scope = { always = yes } } # Essentially a check that the previous emperor actually exists
				}
			}
		}

		dynasty = {
			FROM = { #default dynasty for new emperor
				value = 99 #might drop from modifiers -- highest value will be picked instead (unless equal, then it will randomize)
			}
			actually_culture = {
				value = 0
				additive_modifier = {
					value = 100
					NOT = { FROM = { character = yes } }
				}
				additive_modifier = { #Fix for simulating Chinese history on old save boot-up
					value = 100
					random < 12
					has_game_started = no
				}
			}
		}
		
		likes = {
			likes_concubines = {
				value = 300
				modifier = {
					factor = 0.1
					FROMFROM = { is_female = yes }
				}
			}
			likes_eunuchs = {
				value = 300
			}
			likes_wealth = {
				value = 300
			}
			likes_tributaries = {
				value = 100
			}
			likes_indians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							culture_group = indo_aryan_group
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			likes_germanics = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_germanics = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			likes_altaics = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_altaics = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			likes_arabs = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_arabs = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			likes_iranians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_iranians = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			likes_mesoamericans = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_mesoamericans = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
			}
			
			likes_muslims = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = muslim
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { religion_group = muslim }
				}
			}
			likes_christians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = christian
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { religion_group = christian }
				}
			}
			likes_jews = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = jewish_group
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { likes_jews = yes }
				}
			}
			likes_mazdans = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = zoroastrian_group
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion_group = zoroastrian_group }
				}
			}
			likes_buddhists = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion = buddhist
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { religion = buddhist }
				}
			}
			likes_hindus = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion = hindu
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { religion = hindu }
				}
			}
			likes_tengris = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_tengris = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0.5
					FROMFROM = { likes_tengris = yes }
				}
			}
		}
		
		dislikes = {
			likes_concubines = {
				value = 100
				modifier = {
					factor = 5.0
					FROMFROM = { is_female = yes }
				}
			}
			likes_eunuchs = {
				value = 100
			}
			likes_tributaries = {
				value = 100
			}
			likes_wealth = {
				value = 100
			}
			likes_indians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							culture_group = indo_aryan_group
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						culture_group = indo_aryan_group
					}
				}
			}
			likes_germanics = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_germanics = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						likes_germanics = yes
					}
				}
			}
			likes_altaics = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_altaics = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						likes_altaics = yes
					}
				}
			}
			likes_arabs = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_arabs = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						likes_arabs = yes
					}
				}
			}
			likes_iranians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_iranians = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						likes_iranians = yes
					}
				}
			}
			likes_mesoamericans = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_mesoamericans = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = {
						likes_mesoamericans = yes
					}
				}
			}
			likes_muslims = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = muslim
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion_group = muslim }
				}
			}
			likes_christians = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = christian
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion_group = christian }
				}
			}
			likes_jews = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = jewish_group
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion_group = jewish_group }
				}
			}
			likes_mazdans = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion_group = zoroastrian_group
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion_group = zoroastrian_group }
				}
			}
			likes_buddhists = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion = buddhist
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion = buddhist }
				}
			}
			likes_hindus = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							religion = hindu
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { religion = hindu }
				}
			}
			likes_tengris = {
				value = 100
				modifier = {
					factor = 0
					NOT = {
						any_province = {
							likes_tengris = yes
							is_within_diplo_range = offmap_china
						}
					}
				}
				modifier = {
					factor = 0
					FROMFROM = { likes_tengris = yes }
				}
			}
		}
	}
	
    diplomatic_range = { #Already includes the western governor's "normal" diplo range
        OR = {
            has_game_rule = {
                name = chinese_interactions
                value = all
            }
            AND = {
                has_game_rule = {
                    name = chinese_interactions
                    value = within_range
                }
                OR = {
                    top_liege = {
                        suzerain = {
                            has_landed_title = e_china_west_governor
                        }
                    }
                    any_neighbor_independent_ruler = {
                        OR = {
                            has_landed_title = e_china_west_governor
                            suzerain = {
                                has_landed_title = e_china_west_governor
                            }
                        }
                    }
                    any_realm_province = { #Is within reach of the silk road
                        OR = {
                            trade_route = silk_road
                            region = world_korea
                        }
                    }
                }
            }
            AND = {
                has_game_rule = {
                    name = chinese_interactions
                    value = restricted
                }
                OR = {
                    top_liege = {
                        suzerain = {
                            has_landed_title = e_china_west_governor
                        }
                    }
                    any_neighbor_independent_ruler = {
                        has_landed_title = e_china_west_governor
                    }
                    any_realm_province = { #Is within the Chinese region of influence
                        OR = {
                            region = world_korea
                        }
                    }
                }              
            }
        }
    }
}
