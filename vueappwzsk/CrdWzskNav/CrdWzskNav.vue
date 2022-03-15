<template>
	<div v-if="initdone">
		<div class="d-flex pa-2 align-center">
			<img src="../../assets/logo.png" height="56" alt="logo" class="mr-1">
			<div>
				<div class="title font-weight-bold text-uppercase primary--text mx-2">{{CptTitle}}</div>
				<div class="caption grey--text mx-2">{{CptVersion}}</div>
			</div>
		</div>

		<v-divider/>

		<v-list-item
			active-class="primary--text"
			v-on:click="handleMitClick('MitAppAbtClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitAppAbt}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitAppLoiAvail"
			active-class="primary--text"
			v-on:click="handleMitClick('MitAppLoiClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitAppLoi}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-divider/>

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

		<v-divider/>

		<v-list-item small disabled dense>
			<v-list-item-content>
				<v-list-item-title class="overline">Administration</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdUsgAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdUsgClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdUsg}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdUsrAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdUsrClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdUsr}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdPrsAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdPrsClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdPrs}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdScfAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdScfClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdScf}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item small disabled dense>
			<v-list-item-content>
				<v-list-item-title class="overline">Operation</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdLlvAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdLlvClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdLlv}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdLivAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdLivClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdLiv}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item small disabled dense>
			<v-list-item-content>
				<v-list-item-title class="overline">Gallery</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdOgrAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdOgrClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdOgr}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdObjAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdObjClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdObj}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdSesAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdSesClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdSes}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdShtAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdShtClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdSht}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

		<v-list-item
			v-if="statshr.MitCrdFilAvail"
			active-class="primary--text"
			v-on:click="handleMitCrdopenClick('MitCrdFilClick')"
		>
			<v-list-item-content>
				<v-list-item-title>{{tag.MitCrdFil}}</v-list-item-title>
			</v-list-item-content>
		</v-list-item>

	</div>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

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
			handleMitClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitCrdopenClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppCrdopenReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskNav) this.continf = dpcheng.ContInfWzskNav;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskNav) this.statapp = dpcheng.StatAppWzskNav;
				if (dpcheng.StatShrWzskNav) this.statshr = dpcheng.StatShrWzskNav;
				if (dpcheng.TagWzskNav) {
					Wzsk.unescapeBlock(dpcheng.TagWzskNav);
					this.tag = dpcheng.TagWzskNav;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppCrdopenReply") this.handleDpchAppCrdopenReply(obj.dpcheng);
				else if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDoReply") this.handleDpchAppDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskNavData") this.mergeDpchEngData(dpcheng)
			},

			handleDpchAppCrdopenReply: function(dpcheng) {
				if (dpcheng.accepted) {
					//console.log("CrdWzskNav.handleDpchAppCrdopenReply() accepted");

					this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});

				} else {
					//console.log("CrdWzskNav.handleDpchAppCrdopenReply() denied");
				}
			}
		},

		computed: {
			CptTitle: function() {
				return Wzsk.title;
			},

			CptVersion: function() {
				return("v" + Wzsk.version);
			}
		},

		data: () => ({
			initdone: false,

			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null
		})
	}
</script>
