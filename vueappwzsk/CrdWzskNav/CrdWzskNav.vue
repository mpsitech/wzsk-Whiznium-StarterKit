<template>
	<div v-if="initdonePnls">
		<div class="d-flex pa-2 align-center">
			<img src="../../assets/logo.png" height="56" alt="logo" class="mr-1">
			<div>
				<div class="title font-weight-bold text-uppercase primary--text mx-2">{{CptTitle}}</div>
				<div class="caption grey--text mx-2">{{CptVersion}}</div>
			</div>
		</div>

		<v-divider/>

		<v-list>
			<v-list-item-group v-model="MenApp">
				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppAbtClick')"
					value="MitAppAbt"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppAbt}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					v-if="statshr.MitAppLoiAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppLoiClick')"
					value="MitAppLoi"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppLoi}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group>
				<v-list-item
					v-if="statshr.MitSesSpsAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesSpsClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesSps}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesTrmClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesTrm}}</v-list-item-title>
					</v-list-item-content>
					<v-tooltip right>
						<template v-slot:activator="{on,attrs}">
							<v-list-item-icon>
								<v-icon v-bind="attrs" v-on="on">mdi-information-outline</v-icon>
							</v-list-item-icon>
						</template>
						{{continf.MtxSesSes1 + " " + continf.MtxSesSes2 + " " + continf.MtxSesSes3}}
					</v-tooltip>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group v-for="({sref, mits}, i) in MbarContent" :key="i" v-model="MbarContent[i].mit">
				<v-list-item small disabled dense class="grey lighten-5">
					<v-list-item-content :style="{'text-align':'right'}">
						<v-list-item-title class="grey--text text--darken-4 overline">{{MenContentHdg(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>

				<v-list-item
					v-for="(sref, j) in mitsContent(mits)"
					:key="j"
					active-class="grey lighten-5"
					class="grey lighten-5"
					v-on:click="handleMitContentClick(sref + 'Click')"
					:value="sref"
					:disabled="!MitContentActive(sref)"
				>
					<v-list-item-content>
						<v-list-item-title>{{MitContent(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>
			</v-list-item-group>

			<v-list-item small disabled dense>
				<v-list-item-content :style="{'text-align':'right'}">
					<v-list-item-title class="overline">{{pnlheadbar.tag.MenCrd}}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>

			<v-divider/>

			<v-list-item-group mandatory>
				<v-list-group v-for="({pnlsref, mits}, i) in MenCrd" :key="i">
					<template v-slot:activator>
						<v-list-item-content>
							<v-list-item-title>{{MenCrdHdg(pnlsref)}}</v-list-item-title>
						</v-list-item-content>
					</template>

					<v-list-item
						v-for="(sref, j) in mitsCrd(mits)"
						:key="j"
						active-class="primary--text"
						v-on:click="handleMitCrdopenClick(sref + 'Click')"
						:value="sref"
						:disabled="!MitCrdActive(sref)"
					>
						<v-tooltip right>
							<template v-slot:activator="{on,attrs}">
								<v-list-item-content v-bind="attrs" v-on="on">
									<v-list-item-title>{{MitCrd(sref)}}</v-list-item-title>
								</v-list-item-content>
							</template><span v-html="LstHist(pnlsref, sref.substring(3 + 3))"/>
						</v-tooltip>
					</v-list-item>
				</v-list-group>

				<v-divider/>
			</v-list-item-group>
		</v-list>
	</div>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskNav',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("CrdWzskNav.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleMitClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzskNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitCrdopenClick: function(ctlsref) {
				if (this.content.sref.substring(3 + 4) == ctlsref.substring(3 + 3, 3 + 3 + 3)) return;

				const dpchapp = {
					"DpchAppWzskNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppCrdopenReply"});
			},

			handleButClick_other: function(sref, scrJref, ctlsref) {
				const dpchapp = {
					["DpchAppWzskNav" + sref + "Do"]: {
						"scrJref": scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitContentClick: function(ctlsref) {
				const dpchapp = {
					["DpchApp" + this.content.sref.substring(3) + "Do"]: {
						"scrJref": this.content.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.content.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"}); // reply ends up in content card
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWzskNav) this.continf = dpcheng.ContInfWzskNav;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskNav) this.statapp = dpcheng.StatAppWzskNav;
				if (dpcheng.StatShrWzskNav) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWzskNav.scrJrefDlgloaini != "");
						dlgclose = (this.statshr.scrJrefDlgloaini != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzskNav.scrJrefDlgloaini != "") {
								srefDlg = "DlgWzskNavLoaini";
								scrJrefDlg = dpcheng.StatShrWzskNav.scrJrefDlgloaini;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzskNav;
				}
				if (dpcheng.TagWzskNav) {
					Wzsk.unescapeBlock(dpcheng.TagWzskNav);
					this.tag = dpcheng.TagWzskNav;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			/*
			*/
			mergeDpchEngData_pnlheadbar: function(dpcheng) {
				if (dpcheng.StatShrWzskNavHeadbar) this.pnlheadbar.statshr = dpcheng.StatShrWzskNavHeadbar;
				if (dpcheng.StgInfWzskNavHeadbar) this.pnlheadbar.stginf = dpcheng.StgInfWzskNavHeadbar;
				if (dpcheng.TagWzskNavHeadbar) {
					Wzsk.unescapeBlock(dpcheng.TagWzskNavHeadbar);
					this.pnlheadbar.tag = dpcheng.TagWzskNavHeadbar;
				}
			},

			mergeDpchEngData_pnladmin: function(dpcheng) {
				if (dpcheng.ContIacWzskNavAdmin) this.pnladmin.contiac = dpcheng.ContIacWzskNavAdmin;
				if (dpcheng.FeedFLstPrs) this.pnladmin.feedFLstPrs = dpcheng.FeedFLstPrs;
				if (dpcheng.FeedFLstUsg) this.pnladmin.feedFLstUsg = dpcheng.FeedFLstUsg;
				if (dpcheng.FeedFLstUsr) this.pnladmin.feedFLstUsr = dpcheng.FeedFLstUsr;
				if (dpcheng.StatAppWzskNavAdmin) this.pnladmin.statapp = dpcheng.StatAppWzskNavAdmin;
				if (dpcheng.StatShrWzskNavAdmin) this.pnladmin.statshr = dpcheng.StatShrWzskNavAdmin;
				if (dpcheng.TagWzskNavAdmin) {
					Wzsk.unescapeBlock(dpcheng.TagWzskNavAdmin);
					this.pnladmin.tag = dpcheng.TagWzskNavAdmin;
				}
			},

			mergeDpchEngData_pnlop: function(dpcheng) {
				if (dpcheng.ContIacWzskNavOp) this.pnlop.contiac = dpcheng.ContIacWzskNavOp;
				if (dpcheng.FeedFLstFil) this.pnlop.feedFLstFil = dpcheng.FeedFLstFil;
				if (dpcheng.StatAppWzskNavOp) this.pnlop.statapp = dpcheng.StatAppWzskNavOp;
				if (dpcheng.StatShrWzskNavOp) this.pnlop.statshr = dpcheng.StatShrWzskNavOp;
				if (dpcheng.TagWzskNavOp) {
					Wzsk.unescapeBlock(dpcheng.TagWzskNavOp);
					this.pnlop.tag = dpcheng.TagWzskNavOp;
				}
			},

			/*
			*/

			mergeDpchEngData_content: function(dpcheng) {
				if (dpcheng["StatShr" + this.content.sref.substring(3)]) this.content.statshr = dpcheng["StatShr" + this.content.sref.substring(3)];
				if (dpcheng["Tag" + this.content.sref.substring(3)]) {
					Wzsk.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3)]);
					this.content.tag = dpcheng["Tag" + this.content.sref.substring(3)];
				}

				this.$forceUpdate();
			},

			mergeDpchEngData_contentpnlheadbar: function(dpcheng) {
				if (dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]) {
					Wzsk.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]);
					this.content.pnlheadbar.tag = dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"];
				}

				this.MbarContent = this["Mbar" + this.content.sref.substring(3 + 4)]
			},

			handleCrdopen: function(obj) {
				//console.log(obj.srefCrd);
				this.MenNav = "MitCrd" + obj.srefCrd.substring(3 + 4);

				this.content.sref = obj.srefCrd;
				this.content.scrJref = obj.scrJrefCrd;

				this.content.statshr = {};
				this.content.tag = {};

				this.content.initdone = false;
				this.content.pnlheadbar.initdone = false;

				this.initOther(this.content.scrJref);

				// obj content {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false}
			},

			handleAlrdlgclose: function() {
				this.MenApp = 0;
				for (var men in this.MbarContent) this.MbarContent[men].mit = 0
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppCrdopenReply") this.handleDpchAppCrdopenReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDoReply") this.handleDpchAppDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleUpdate: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskNavData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdonePnls) {
					if (obj.dpcheng.scrJref == this.statshr.scrJrefAdmin) this.mergeDpchEngData_pnladmin(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefMon) this.mergeDpchEngData_pnlmon(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.mergeDpchEngData_pnlpre(obj.dpcheng);

					if (this.content.initdone) if (obj.dpcheng.scrJref == this.content.scrJref) this.mergeDpchEngData_content(obj.dpcheng);
				}
			},

			initOther: function(scrJref) {
				const dpchapp = {
					"DpchAppWzskInit": {
						"scrJref": scrJref
					}
				};

				this.$emit("request", {scrJref: scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
			},

			handleDpchAppInitReply: function(dpcheng) {
				if (dpcheng.scrJref == this.scrJref) {
					this.mergeDpchEngData(dpcheng);
					this.initdone = true;
				}

				if (this.initdone) {
					/*
					*/
					if (dpcheng.scrJref == this.statshr.scrJrefHeadbar) {
						this.mergeDpchEngData_pnlheadbar(dpcheng);
						this.statapp.initdoneHeadbar = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAdmin) {
						this.mergeDpchEngData_pnladmin(dpcheng);
						this.statapp.initdoneAdmin = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefOp) {
						this.mergeDpchEngData_pnlop(dpcheng);
						this.statapp.initdoneOp = true;
					} else if (dpcheng.scrJref == this.content.scrJref) {
						this.mergeDpchEngData_content(dpcheng);
						this.content.initdone = true;
					}

					if (!this.statapp.initdoneHeadbar) this.initOther(this.statshr.scrJrefHeadbar);
					else if (!this.statapp.initdoneAdmin) this.initOther(this.statshr.scrJrefAdmin);
					else if (!this.statapp.initdoneOp) this.initOther(this.statshr.scrJrefOp);
					/*
					*/
					else this.initdonePnls = true;

					if (this.content.initdone) {
						if (dpcheng.scrJref == this.content.statshr.scrJrefHeadbar) {
							this.mergeDpchEngData_contentpnlheadbar(dpcheng);
							this.content.pnlheadbar.initdone = true;
						}
		
						if (!this.content.pnlheadbar.initdone) this.initOther(this.content.statshr.scrJrefHeadbar);
					}
				}
			},

			handleDpchAppDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskNavData") this.mergeDpchEngData(dpcheng);
			},

			handleDpchAppCrdopenReply: function(dpcheng) {
				if (dpcheng.accepted) {
					//console.log("CrdWzskNav.handleDpchAppCrdopenReply() accepted");

					this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});

				} else {
					//console.log("CrdWzskNav.handleDpchAppCrdopenReply() denied");
				}
			},

			// (static) CrdNav.MenApp: tag

			// (static) CrdNav.MenSes: tag, continf (pop-up)

			// (dynamic) CrdNav.MenCrd: pnl*.tag (module), crd.tag (mit). pnl*.continf (history)
			MenCrdHdg: function(pnlsref) {
				if (this[pnlsref] == null) return pnlsref;
				return this[pnlsref].tag.Cpt;
			},

			mitsCrd: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.statshr[ctlsref + "Avail"] != null) if (this.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}
					
				return mits
			},

			MitCrd: function(ctlsref) {
				if (this.tag[ctlsref] == null) return ctlsref;
				return this.tag[ctlsref]
			},

			MitCrdActive: function(ctlsref) {
				if (this.statshr[ctlsref + "Active"] == null) return true;
				return this.statshr[ctlsref + "Active"]
			},

			// (dynamic) PnlNavPre: tag, continf

			// (dynamic) content.Mbar: pnlheadbar.tag (men), crd.tag (mit)
			MenContentHdg: function(ctlsref) {
				if (this.content.pnlheadbar.tag == null) return ctlsref;
				if (this.content.pnlheadbar.tag[ctlsref] == null) return ctlsref;
				return this.content.pnlheadbar.tag[ctlsref];
			},

			mitsContent: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.content.statshr[ctlsref + "Avail"] != null) if (this.content.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}

				return mits
			},

			MitContent: function(ctlsref) {
				if (this.content.tag == null) return ctlsref;
				if (this.content.tag[ctlsref] == null) return ctlsref;
				return this.content.tag[ctlsref];
			},

			MitContentActive: function(ctlsref) {
				if (this.content.statshr == null) return true;
				if (this.content.statshr[ctlsref + "Active"] == null) return true;
				return this.content.statshr[ctlsref + "Active"]
			},

			LstHist: function(pnlsref, short) {
				var retval = "";
				const feed = this[pnlsref]["feedFLst" + short];

				if (feed != null)
					for (var i = 0; i < feed.length; i++) {
						var fi = feed[i];
						retval += "<p class='mb-0'>" + fi.tit1 + "</p>";
					}

				return retval;
			}
		},

		computed: {
			CptTitle: function() {
				return Wzsk.title;
			},

			CptVersion: function() {
				return("v" + Wzsk.version);
			},

			MenApp: {
				get() {
					return this.MenApp_last;
				},
				set(sel) {
					if (sel == null) this.MenApp_last = 0;
					else this.MenApp_last = sel;
					
					return sel;
				}
			},

			mitsPre: function() {
				var mits = [];

				for (const short of this.MenPre) if (this.pnlpre.statshr["Txt" + short + "Avail"]) mits.push(short);

				return mits
			}
		},

		data: () => ({
			initdone: false,
			initdonePnls: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/

			MenApp_last: 0,

			/*
			*/
			/*
			*/

			/*
			*/
			MenCrd: [
				{
					pnlsref: "pnladmin",
					mits: ["MitCrdUsg", "MitCrdUsr", "MitCrdPrs", "MitCrdPrf"]
				},
				{
					pnlsref: "pnlop",
					mits: ["MitCrdLlv", "MitCrdVtr", "MitCrdHwc", "MitCrdFil"]
				}
			],
			/*
			*/

			/*
			*/
			pnlheadbar: {
			},

			pnladmin: {
			},

			pnlop: {
			},

			/*
			*/

			content: {
				sref: "",
				scrJref: "",

				statshr: null,

				pnlheadbar: {
					initdone: false
				},

				initdone: false
			},

			/*
			*/
			MbarUsg: [
			],

			MbarUsr: [
			],

			MbarPrs: [
			],

			MbarPrf: [
				{
					sref: "MenCrd",
					mits: ["MitCrdRvr", "MitCrdSto"]
				}
			],

			MbarLlv: [
			],

			MbarVtr: [
			],

			MbarHwc: [
			],

			MbarFil: [
				{
					sref: "MenCrd",
					mits: ["MitCrdDld"]
				}
			],

			/*
			*/

			MbarContent: null,

			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
