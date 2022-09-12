<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWzskUsrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskUsrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzskUsrAAccess
						v-on:request="handleRequest"
						ref="PnlWzskUsrAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzskUsr1NSession
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskUsr1NSession"
						:scrJref=statshr.scrJref1NSession
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzskUsrMNUsergroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzskUsrMNUsergroup"
						:scrJref=statshr.scrJrefMNUsergroup
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskUsrDetail from './PnlWzskUsrDetail';
	import PnlWzskUsrAAccess from './PnlWzskUsrAAccess';
	import PnlWzskUsr1NSession from './PnlWzskUsr1NSession';
	import PnlWzskUsrMNUsergroup from './PnlWzskUsrMNUsergroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskUsrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskUsrDetail,
			PnlWzskUsrAAccess,
			PnlWzskUsr1NSession,
			PnlWzskUsrMNUsergroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzskUsrRec.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzskUsrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzskUsrRec) this.continf = dpcheng.ContInfWzskUsrRec;
				if (dpcheng.StatAppWzskUsrRec) this.statapp = dpcheng.StatAppWzskUsrRec;
				if (dpcheng.StatShrWzskUsrRec) this.statshr = dpcheng.StatShrWzskUsrRec;
				if (dpcheng.TagWzskUsrRec) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsrRec);
					this.tag = dpcheng.TagWzskUsrRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWzskVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzskUsrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzskUsrAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWzskUsr1NSession.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWzskUsrMNUsergroup.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskUsrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskUsrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzskVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzskUsrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzskUsrAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWzskUsr1NSession.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWzskUsrMNUsergroup.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
